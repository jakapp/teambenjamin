#include "sqlinterface.h"

SqlInterface::SqlInterface()
{
    //Create the database environment
    env = Environment::createEnvironment(Environment::DEFAULT);
    cout << "Environment created..." << endl;
}

SqlInterface::~SqlInterface()
{
    //Code to close the database connection
    env->terminateConnection(conn);
    Environment::terminateEnvironment(env);
    cout << "Connection to database closed." << endl;
}

void SqlInterface::connect()
{
    cout << "Username: ";
    cin >> user;
    cout << endl << "Password: ";
    cin >> passwd;
    cout << "Database: ";
    cin >> db;
    cout << endl;

    //    user = "scott";
    //    passwd = "password";
    //    db = "localhost:1521/skynetdb";

    conn = env->createConnection(user,passwd,db);
    cout << "Connection to database created..." << endl;
}

void SqlInterface::insert()
{
    cout << endl;
    cout << "Insert> ";
    cin.ignore(1000, '\n');
    getline(cin,query);

    stmt = conn->createStatement(query);

    try{
        stmt->executeUpdate();
    } catch(SQLException ex){
        cout<<"Exception thrown for insert"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }
    conn->terminateStatement(stmt);
}

void SqlInterface::select()
{
    ResultSet *rset;
    cout << endl;
    cout << "Select> ";
    cin.ignore(1000, '\n');
    getline(cin,query);

    stmt = conn->createStatement(query);
    try{
        rset = stmt->executeQuery();
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }

    vector<MetaData> data = rset->getColumnListMetaData();

    for(int i = 0; i < data.size(); i++){
        MetaData column = data[i];
        cout << column.getString(MetaData::ATTR_NAME);
        cout << setw(30);
    }
    cout << setw(0);
    cout << endl;

    try{
        while(rset->next()){
            for(int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                cout << temp << setw(30);
            }
            cout << setw(0);
            cout << endl;
        }
        cout << endl;
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }

    stmt->closeResultSet (rset);
    conn->terminateStatement (stmt);
}

void SqlInterface::display()
{
    string input;
    string selTemp;
    int columnCount = 0;
    ResultSet *rset;

    cout << endl;
    cout << "Display> ";
    cin >> input;

    selTemp = "select * from ";
    query = selTemp + input;
    cout << "query: " << query << endl;
    stmt = conn->createStatement(query);

    try{
        rset = stmt->executeQuery();
    } catch(SQLException ex) {
        cout<<"Exception thrown for display"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }

    MetaData data = conn->getMetaData(input, MetaData::PTYPE_TABLE);
    columnCount = data.getInt(MetaData::ATTR_NUM_COLS);

    vector<MetaData>listOfColumns = data.getVector(MetaData::ATTR_LIST_COLUMNS);

    for(int i = 0; i < columnCount; i++){
        MetaData column = listOfColumns[i];
        cout << column.getString(MetaData::ATTR_NAME);
        cout << setw(30);
    }
    cout << setw(0);
    cout << endl;

    try{
        while(rset->next()){
            for(int i = 0; i < columnCount; i++){
                temp = rset->getString(i+1);
                cout << temp << setw(30);
            }
            cout << setw(0);
            cout << endl;

        }
        cout << endl;
    }
    catch(SQLException ex){
        cout<<"Exception thrown for display"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }

    stmt->closeResultSet (rset);
    conn->terminateStatement (stmt);
}

void SqlInterface::deleteRow()
{
    cout << endl;
    cout << "Delete> ";
    cin.ignore(1000, '\n');
    getline(cin,query);

    stmt = conn->createStatement(query);

    try{
        stmt->executeUpdate();
    } catch(SQLException ex){
        cout<<"Exception thrown for deleteRow" << endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }
    conn->terminateStatement(stmt);
}

void SqlInterface::createTable()
{
    cout << endl;
    cout << "Create> ";
    cin.ignore(1000, '\n');
    getline(cin,query);

    stmt = conn->createStatement(query);

    try{
        stmt->executeUpdate();
    } catch(SQLException ex){
        cout<<"Exception thrown for createTable" << endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }
    conn->terminateStatement(stmt);
}

void SqlInterface::modifyRow()
{
    cout << endl;
    cout << "Modify> ";
    cin.ignore(1000, '\n');
    getline(cin,query);

    stmt = conn->createStatement(query);

    try{
        stmt->executeUpdate();
    } catch(SQLException ex){
        cout<<"Exception thrown for modifyRow" << endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }
    conn->terminateStatement(stmt);
}
