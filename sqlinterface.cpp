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

void SqlInterface::connect(string user, string passwd, string db)
{
    //    user = "scott";
    //    passwd = "password";
    //    db = "localhost:1521/skynetdb";

    cout << "Username: ";
    cout << user << endl;
    cout << "Password: ";
    cout << passwd << endl;
    cout << "Database: ";
    cout << db << endl;
    cout << endl;

    conn = env->createConnection(user,passwd,db);
    cout << "Connection to database created..." << endl;
}

MaintenanceContainer SqlInterface::searchMaintenanceData(string query){
    ResultSet *rset;
    MaintenanceContainer mContainer;
    int temp2 = 0;

    //query = "select * from maintenance where costs=100";

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    mContainer.setCarId(temp2);
                    break;
                case 1: mContainer.setDamages(temp);
                    break;
                case 2: temp2 = atoi(temp.c_str());
                    mContainer.setCosts(temp2);
                    break;
                case 3: mContainer.setStartDate(temp);
                    break;
                case 4: mContainer.setFinishDate(temp);
                    break;
                }
            }
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

    return mContainer;
}

CustomerContainer SqlInterface::searchCustomerData(string query){
    ResultSet *rset;
    CustomerContainer cContainer;
    int temp2 = 0;

    //query = "select * from maintenance where costs=100";

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    cContainer.setCarId(temp2);
                    break;
                case 1: cContainer.setFirstName(temp);
                    break;
                case 2: cContainer.setLastName(temp);
                    break;
                case 3: cContainer.setAddress(temp);
                    break;
                case 4: cContainer.setState(temp);
                    break;
                case 5:temp2 = atoi(temp.c_str());
                    cContainer.setZip(temp2);
                    break;
                case 6: cContainer.setDeliveryDate(temp);
                    break;
                case 7: cContainer.setScheduledMaintenance(temp);
                    break;
                case 8: cContainer.setUnscheduledRepairs(temp);
                    break;
                }
            }
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

    return cContainer;
}

CarContainer SqlInterface::searchCarData(string query){
    ResultSet *rset;
    CarContainer cContainer;
    int temp2 = 0;

    //query = "select * from maintenance where costs=100";

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    cContainer.setCarId(temp2);
                    break;
                case 1: cContainer.setPerformance(temp);
                    break;
                case 2: cContainer.setHandeling(temp);
                    break;
                case 3: cContainer.setInstrumentation(temp);
                    break;
                case 4: cContainer.setSafetySecurity(temp);
                    break;
                case 5: cContainer.setDesign(temp);
                    break;
                case 6: cContainer.setAudio(temp);
                    break;
                case 7: cContainer.setComfort(temp);
                    break;
                case 8: cContainer.setMaintenance(temp);
                    break;
                case 9: cContainer.setWarranty(temp);
                    break;
                case 10: cContainer.setPackages(temp);
                    break;
                case 11: cContainer.setMake(temp);
                    break;
                case 12: cContainer.setModel(temp);
                    break;
                }
            }
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

    return cContainer;
}

SalesContainer SqlInterface::searchSalesData(string query){
    ResultSet *rset;
    SalesContainer sContainer;
    int temp2 = 0;

    //query = "select * from maintenance where costs=100";

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    sContainer.setCarId(temp2);
                    break;
                case 1: sContainer.setAvailability(temp);
                    break;
                case 2: sContainer.setDeliveryDate(temp);
                    break;
                case 3: temp2 = atoi(temp.c_str());
                    sContainer.setCost(temp2);
                    break;
                case 4: sContainer.setDateSold(temp);
                    break;
                case 5: sContainer.setFirstName(temp);
                    break;
                case 6: sContainer.setLastName(temp);
                    break;
                case 7: sContainer.setMake(temp);
                    break;
                case 8: sContainer.setModel(temp);
                    break;
                }
            }
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

    return sContainer;
}

vector<MaintenanceContainer> SqlInterface::getMaintenanceData(){
    ResultSet *rset;
    MaintenanceContainer mContainer;
    int temp2 = 0;
    string query = "select * from maintenance";
    vector<MaintenanceContainer> vContainer;

    if(this == 0 || this == NULL)
        return vContainer;

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    mContainer.setCarId(temp2);
                    break;
                case 1: mContainer.setDamages(temp);
                    break;
                case 2: temp2 = atoi(temp.c_str());
                    mContainer.setCosts(temp2);
                    break;
                case 3: mContainer.setStartDate(temp);
                    break;
                case 4: mContainer.setFinishDate(temp);
                    break;
                }
            }
            vContainer.push_back(mContainer);
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

    return vContainer;
}

vector<CustomerContainer> SqlInterface::getCustomerData(){
    ResultSet *rset;
    CustomerContainer cContainer;
    int temp2 = 0;
    vector<CustomerContainer> vContainer;
    string query = "select * from customers";

    if(this == 0 || this == NULL)
        return vContainer;

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    cContainer.setCarId(temp2);
                    break;
                case 1: cContainer.setFirstName(temp);
                    break;
                case 2: cContainer.setLastName(temp);
                    break;
                case 3: cContainer.setAddress(temp);
                    break;
                case 4: cContainer.setState(temp);
                    break;
                case 5:temp2 = atoi(temp.c_str());
                    cContainer.setZip(temp2);
                    break;
                case 6: cContainer.setDeliveryDate(temp);
                    break;
                case 7: cContainer.setScheduledMaintenance(temp);
                    break;
                case 8: cContainer.setUnscheduledRepairs(temp);
                    break;
                }
            }
            vContainer.push_back(cContainer);
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

    return vContainer;
}

vector<CarContainer> SqlInterface::getCarData(){
    ResultSet *rset;
    CarContainer cContainer;
    int temp2 = 0;
    vector<CarContainer> vContainer;
    string query = "select * from cars";


    if(this == 0 || this == NULL)
        return vContainer;

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    cContainer.setCarId(temp2);
                    break;
                case 1: cContainer.setPerformance(temp);
                    break;
                case 2: cContainer.setHandeling(temp);
                    break;
                case 3: cContainer.setInstrumentation(temp);
                    break;
                case 4: cContainer.setSafetySecurity(temp);
                    break;
                case 5: cContainer.setDesign(temp);
                    break;
                case 6: cContainer.setAudio(temp);
                    break;
                case 7: cContainer.setComfort(temp);
                    break;
                case 8: cContainer.setMaintenance(temp);
                    break;
                case 9: cContainer.setWarranty(temp);
                    break;
                case 10: cContainer.setPackages(temp);
                    break;
                case 11: cContainer.setMake(temp);
                    break;
                case 12: cContainer.setModel(temp);
                    break;
                }
            }
            vContainer.push_back(cContainer);
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

    return vContainer;
}

vector<SalesContainer> SqlInterface::getSalesData(){
    ResultSet *rset;
    SalesContainer sContainer;
    int temp2 = 0;
    string query = "select * from sales";
    vector<SalesContainer> vContainer;

    if(this == 0 || this == NULL)
        return vContainer;

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

    try{
        while(rset->next()){
            for(unsigned int i = 0; i < data.size(); i++){
                temp = rset->getString(i+1);
                switch(i)
                {
                case 0: temp2 = atoi(temp.c_str());
                    sContainer.setCarId(temp2);
                    break;
                case 1: sContainer.setAvailability(temp);
                    break;
                case 2: sContainer.setDeliveryDate(temp);
                    break;
                case 3: temp2 = atoi(temp.c_str());
                    sContainer.setCost(temp2);
                    break;
                case 4: sContainer.setDateSold(temp);
                    break;
                case 5: sContainer.setFirstName(temp);
                    break;
                case 6: sContainer.setLastName(temp);
                    break;
                case 7: sContainer.setMake(temp);
                    break;
                case 8: sContainer.setModel(temp);
                    break;
                }
            }
            vContainer.push_back(sContainer);
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

    return vContainer;
}

void SqlInterface::deleteRow(string table, int car_id)
{
    string temp = "delete from ";
    string temp2;
    stringstream ss;

    ss << car_id;
    temp2 = ss.str();

    temp = temp + table + " where car_id=" + temp2 + ";";
    cout << temp;


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


/*Depreciated functions. Can be used if needed however they are not tested with this project. */

//void SqlInterface::display()
//{
//    string input;
//    string selTemp;
//    int columnCount = 0;
//    ResultSet *rset;

//    cout << endl;
//    cout << "Display> ";
//    cin >> input;

//    selTemp = "select * from ";
//    query = selTemp + input;
//    cout << "query: " << query << endl;

//    query = "select * from maintenance";
//    stmt = conn->createStatement(query);

//    try{
//        rset = stmt->executeQuery();
//    } catch(SQLException ex) {
//        cout<<"Exception thrown for display"<<endl;
//        cout<<"Error number: "<<  ex.getErrorCode() << endl;
//        cout<<ex.getMessage() << endl;
//    }

//    MetaData data = conn->getMetaData("maintenance", MetaData::PTYPE_TABLE);
//    columnCount = data.getInt(MetaData::ATTR_NUM_COLS);

//    vector<MetaData>listOfColumns = data.getVector(MetaData::ATTR_LIST_COLUMNS);

//    for(int i = 0; i < columnCount; i++){
//        MetaData column = listOfColumns[i];
//        cout << column.getString(MetaData::ATTR_NAME);
//        cout << setw(30);
//    }
//    cout << setw(0);
//    cout << endl;

//    try{
//        while(rset->next()){
//            for(int i = 0; i < columnCount; i++){
//                temp = rset->getString(i+1);
//                cout << temp << setw(30);
//            }
//            cout << setw(0);
//            cout << endl;

//        }
//        cout << endl;
//    }
//    catch(SQLException ex){
//        cout<<"Exception thrown for display"<<endl;
//        cout<<"Error number: "<<  ex.getErrorCode() << endl;
//        cout<<ex.getMessage() << endl;
//    }

//    stmt->closeResultSet (rset);
//    conn->terminateStatement (stmt);
//}

//void SqlInterface::createTable()
//{
//    cout << endl;
//    cout << "Create> ";
//    cin.ignore(1000, '\n');
//    getline(cin,query);

//    stmt = conn->createStatement(query);

//    try{
//        stmt->executeUpdate();
//    } catch(SQLException ex){
//        cout<<"Exception thrown for createTable" << endl;
//        cout<<"Error number: "<<  ex.getErrorCode() << endl;
//        cout<<ex.getMessage() << endl;
//    }
//    conn->terminateStatement(stmt);
//}

//void SqlInterface::modifyRow()
//{
//    cout << endl;
//    cout << "Modify> ";
//    cin.ignore(1000, '\n');
//    getline(cin,query);

//    stmt = conn->createStatement(query);

//    try{
//        stmt->executeUpdate();
//    } catch(SQLException ex){
//        cout<<"Exception thrown for modifyRow" << endl;
//        cout<<"Error number: "<<  ex.getErrorCode() << endl;
//        cout<<ex.getMessage() << endl;
//    }
//    conn->terminateStatement(stmt);
//}

//void SqlInterface::insert()
//{
//    cout << endl;
//    cout << "Insert> ";
//    cin.ignore(1000, '\n');
//    getline(cin,query);

//    stmt = conn->createStatement(query);

//    try{
//        stmt->executeUpdate();
//    } catch(SQLException ex){
//        cout<<"Exception thrown for insert"<<endl;
//        cout<<"Error number: "<<  ex.getErrorCode() << endl;
//        cout<<ex.getMessage() << endl;
//    }
//    conn->terminateStatement(stmt);
//}

//void SqlInterface::select()
//{
//    ResultSet *rset;
//    cout << endl;
//    cout << "Select> ";
//    cin.ignore(1000, '\n');
//    getline(cin,query);

//    stmt = conn->createStatement(query);
//    try{
//        rset = stmt->executeQuery();
//    }
//    catch(SQLException ex){
//        cout<<"Exception thrown for select"<<endl;
//        cout<<"Error number: "<<  ex.getErrorCode() << endl;
//        cout<<ex.getMessage() << endl;
//    }

//    vector<MetaData> data = rset->getColumnListMetaData();

//    for(unsigned int i = 0; i < data.size(); i++){
//        MetaData column = data[i];
//        cout << column.getString(MetaData::ATTR_NAME);
//        cout << setw(30);
//    }
//    cout << setw(0);
//    cout << endl;

//    try{
//        while(rset->next()){
//            for(unsigned int i = 0; i < data.size(); i++){
//                temp = rset->getString(i+1);
//                cout << temp << setw(30);
//            }
//            cout << setw(0);
//            cout << endl;
//        }
//        cout << endl;
//    }
//    catch(SQLException ex){
//        cout<<"Exception thrown for select"<<endl;
//        cout<<"Error number: "<<  ex.getErrorCode() << endl;
//        cout<<ex.getMessage() << endl;
//    }

//    stmt->closeResultSet (rset);
//    conn->terminateStatement (stmt);
//}
