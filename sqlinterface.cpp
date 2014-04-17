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

    conn = env->createConnection(user,passwd,db);
    cout << "Connection to database created..." << endl;
}

vector<MaintenanceContainer> SqlInterface::searchMaintenanceData(MaintenanceContainer container){
    ResultSet *rset;
    vector<MaintenanceContainer> vContainer;
    int temp2 = 0;
    string query = "select * from Maintenance where ";
    string buffer1;
    string buffer2;
    bool firstValue = true;

    if(container.getCarId() != 0){
        stringstream ss;
        ss << container.getCarId();
        buffer1 = ss.str();
        if(firstValue == false)
           query = query + "and ";
        query = query + "car_id=" + buffer1 + " ";
        firstValue = false;
    }
    if(strcmp(container.getDamages().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "damages='" + container.getDamages() + "' ";
        firstValue = false;
    }
    if(container.getCost() != 0){
        stringstream ss2;
        ss2 << container.getCost();
        buffer2 = ss2.str();
        if(firstValue == false)
           query = query + "and ";
        query = query + "costs=" + buffer2 + " ";
        firstValue = false;
    }
    if(strcmp(container.getStartDate().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "start_date='" + container.getStartDate() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getFinishDate().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "completion_date='" + container.getFinishDate() + "' ";
        firstValue = false;
    }
    if(firstValue == true)
        query = "select * from Sales where car_id=0";

    stmt = conn->createStatement(query);

    try{
        rset = stmt->executeQuery();
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement (stmt);
        return vContainer;
    }

    vector<MetaData> data = rset->getColumnListMetaData();

    try{
        while(rset->next()){
            MaintenanceContainer mContainer;
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
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement (stmt);
        return vContainer;
    }

    stmt->closeResultSet (rset);
    conn->terminateStatement (stmt);

    return vContainer;
}

vector<CustomerContainer> SqlInterface::searchCustomerData(CustomerContainer container){
    ResultSet *rset;
    int temp2 = 0;
    vector<CustomerContainer> vContainer;
    string query = "select * from Customers where ";
    string buffer1;
    string buffer2;
    bool firstValue = true;

    if(container.getCarId() != 0){
        stringstream ss;
        ss << container.getCarId();
        buffer1 = ss.str();
        if(firstValue == false)
           query = query + "and ";
        query = query + "car_id=" + buffer1 + " ";
        firstValue = false;
    }
    if(strcmp(container.getFirstName().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "first_name='" + container.getFirstName() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getLastName().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "last_name='" + container.getLastName() + "' ";
        firstValue = false;
    }
    if(container.getZip() != 0){
        stringstream ss2;
        ss2 << container.getZip();
        buffer2 = ss2.str();
        if(firstValue == false)
           query = query + "and ";
        query = query + "zip=" + buffer2 + " ";
        firstValue = false;
    }
    if(strcmp(container.getAddress().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "address='" + container.getAddress() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getState().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "state='" + container.getState() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getDeliveryDate().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "delivery_date='" + container.getDeliveryDate() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getScheduledMaintenance().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "scheduled_maintenance='" + container.getScheduledMaintenance() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getUnscheduledRepairs().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "unscheduled_repairs='" + container.getUnscheduledRepairs() + "' ";
        firstValue = false;
    }
    if(firstValue == true)
        query = "select * from Sales where car_id=0";

    stmt = conn->createStatement(query);

    try{
        rset = stmt->executeQuery();
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement (stmt);
        return vContainer;
    }

    vector<MetaData> data = rset->getColumnListMetaData();

    try{
        while(rset->next()){
            CustomerContainer cContainer;
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
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement (stmt);
        return vContainer;
    }

    stmt->closeResultSet (rset);
    conn->terminateStatement (stmt);

    return vContainer;
}

vector<CarContainer> SqlInterface::searchCarData(CarContainer container){
    ResultSet *rset;
    int temp2 = 0;
    string query = "select * from Cars where ";
    string buffer1;
    bool firstValue = true;
    vector<CarContainer> vContainer;

    if(container.getCarId() != 0){
        stringstream ss;
        ss << container.getCarId();
        buffer1 = ss.str();
        if(firstValue == false)
           query = query + "and ";
        query = query + "car_id=" + buffer1 + " ";
        firstValue = false;
    }
    if(strcmp(container.getMake().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "make='" + container.getMake() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getModel().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "model='" + container.getModel() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getPerformance().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "performance='" + container.getPerformance() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getHandeling().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "handling='" + container.getHandeling() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getInstrumentation().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "instrumentation='" + container.getInstrumentation() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getSafetySecurity().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "safety_security='" + container.getSafetySecurity() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getDesign().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "design='" + container.getDesign() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getAudio().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "audio='" + container.getAudio() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getComfort().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "comfort='" + container.getComfort() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getMaintenance().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "maintenance='" + container.getMaintenance() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getWarranty().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "warranty='" + container.getWarranty() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getPackages().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "packages='" + container.getPackages() + "' ";
        firstValue = false;
    }
    if(firstValue == true)
        query = "select * from Sales where car_id=0";

    cout << query << endl;

    stmt = conn->createStatement(query);

    try{
        rset = stmt->executeQuery();
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement (stmt);
        return vContainer;
    }

    vector<MetaData> data = rset->getColumnListMetaData();

    try{
        while(rset->next()){
            CarContainer cContainer;
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
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement (stmt);
        return vContainer;
    }

    stmt->closeResultSet (rset);
    conn->terminateStatement (stmt);

    return vContainer;
}

vector<SalesContainer> SqlInterface::searchSalesData(SalesContainer container){
    ResultSet *rset;
    vector<SalesContainer> vContainer;
    int temp2 = 0;
    string query = "select * from Sales where ";
    string buffer1;
    string buffer2;
    bool firstValue = true;

    if(container.getCarId() != 0){
        stringstream ss;
        ss << container.getCarId();
        buffer1 = ss.str();
        if(firstValue == false)
           query = query + "and ";
        query = query + "car_id=" + buffer1 + " ";
        firstValue = false;
    }
    if(strcmp(container.getAvailability().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "availability='" + container.getAvailability() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getDateSold().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "date_sold='" + container.getDateSold() + "' ";
        firstValue = false;
    }
    if(container.getCost() != 0){
        stringstream ss2;
        ss2 << container.getCost();
        buffer2 = ss2.str();
        if(firstValue == false)
           query = query + "and ";
        query = query + "cost=" + buffer2 + " ";
        firstValue = false;
    }
    if(strcmp(container.getDeliveryDate().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "delivery_date='" + container.getDeliveryDate() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getFirstName().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "first_name='" + container.getFirstName() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getLastName().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "last_name='" + container.getLastName() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getMake().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "make='" + container.getMake() + "' ";
        firstValue = false;
    }
    if(strcmp(container.getModel().c_str(), "") != 0){
        if(firstValue == false)
           query = query + "and ";
        query = query + "model='" + container.getModel() + "' ";
        firstValue = false;
    }
    if(firstValue == true)
        query = "select * from Sales where car_id=0";

    cout << query << endl;

    stmt = conn->createStatement(query);

    try{
        rset = stmt->executeQuery();
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement(stmt);
        return vContainer;

    }

    try{
        while(rset->next()){
            SalesContainer sContainer;
            for(int i = 0; i < 9; i++){
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
    }
    catch(SQLException ex){
        cout<<"Exception thrown for select"<<endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
        stmt->closeResultSet (rset);
        conn->terminateStatement(stmt);
        return vContainer;
    }

    stmt->closeResultSet (rset);
    conn->terminateStatement (stmt);

    return vContainer;
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

    temp = temp + table + " where car_id=" + temp2;

    stmt = conn->createStatement(temp);

    try{
        stmt->executeUpdate();
    } catch(SQLException ex){
        cout<<"Exception thrown for deleteRow" << endl;
        cout<<"Error number: "<<  ex.getErrorCode() << endl;
        cout<<ex.getMessage() << endl;
    }
    conn->terminateStatement(stmt);
}

void SqlInterface::maintenanceInsert(vector<MaintenanceContainer> container1, string table)
{
    int value0;
    string value1;
    int value2;
    string value3;
    string value4;
    string query = "insert into ";
    string buffer1;
    string buffer2;

    for(unsigned int j = 0; j < container1.size(); j++){
        value0 = container1[j].getCarId();
        value1 = container1[j].getDamages();
        value2 = container1[j].getCost();
        value3 = container1[j].getStartDate();
        value4 = container1[j].getFinishDate();

        stringstream ss;
        ss << value0;
        buffer1 = ss.str();
        stringstream ss2;
        ss2 << value2;
        buffer2 = ss2.str();
        query = query + table + " values (" + buffer1 + ", " + "'" + value1 + "', " +  buffer2 + ", "
                + "'" + value3 + "', " + "'" + value4 + "')";
        cout << query << endl;

        stmt = conn->createStatement(query);

        try{
            stmt->executeUpdate();
        } catch(SQLException ex){
            cout<<"Exception thrown for insert"<<endl;
            cout<<"Error number: "<<  ex.getErrorCode() << endl;
            cout<<ex.getMessage() << endl;
        }
        conn->terminateStatement(stmt);

        query = "insert into ";
    }
}

void SqlInterface::salesInsert(vector<SalesContainer> container4, string table)
{
    int value0;
    string value1;
    string value2;
    int value3;
    string value4;
    string value5;
    string value6;
    string value7;
    string value8;
    string query = "insert into ";
    string buffer1;
    string buffer2;

    for(unsigned int j = 0; j < container4.size(); j++){
        value0 = container4[j].getCarId();
        value1 = container4[j].getAvailability();
        value2 = container4[j].getDeliveryDate();
        value3 = container4[j].getCost();
        value4 = container4[j].getDateSold();
        value5 = container4[j].getFirstName();
        value6 = container4[j].getLastName();
        value7 = container4[j].getMake();
        value8 = container4[j].getModel();

        stringstream ss;
        ss << value0;
        buffer1 = ss.str();
        stringstream ss2;
        ss2 << value3;
        buffer2 = ss2.str();
        query = query + table + " values (" + buffer1 + ", " + "'" + value1 + "', '" +  value2 + "', "
                + buffer2 + ", '" + value4 + "', '" + value5 + "', '" + value6
                + "', '" + value7 + "', '" + value8 + "')";
        cout << query << endl;

        stmt = conn->createStatement(query);

        try{
            stmt->executeUpdate();
        } catch(SQLException ex){
            cout<<"Exception thrown for insert"<<endl;
            cout<<"Error number: "<<  ex.getErrorCode() << endl;
            cout<<ex.getMessage() << endl;
        }
        conn->terminateStatement(stmt);

        query = "insert into ";
    }
}

void SqlInterface::carInsert(vector<CarContainer> container3, string table)
{
    int value0;
    string value1;
    string value2;
    string value3;
    string value4;
    string value5;
    string value6;
    string value7;
    string value8;
    string value9;
    string value10;
    string value11;
    string value12;
    string query = "insert into ";
    string buffer1;

    for(unsigned int j = 0; j < container3.size(); j++){
        value0 = container3[j].getCarId();
        value1 = container3[j].getPerformance();
        value2 = container3[j].getHandeling();
        value3 = container3[j].getInstrumentation();
        value4 = container3[j].getSafetySecurity();
        value5 = container3[j].getDesign();
        value6 = container3[j].getAudio();
        value7 = container3[j].getComfort();
        value8 = container3[j].getMaintenance();
        value9 = container3[j].getWarranty();
        value10 = container3[j].getPackages();
        value11 = container3[j].getMake();
        value12 = container3[j].getModel();

        stringstream ss;
        ss << value0;
        buffer1 = ss.str();
        query = query + table + " values (" + buffer1 + ", " + "'" + value1 + "', '" +  value2 + "', '"
                + value3 + "', '" + value4 + "', '" + value5 + "', '" + value6
                + "', '" + value7 + "', '" + value8 + "', '" + value9 + "', '" + value10 + "', '"
                + value11 + "', '" + value12 + "')";
        cout << query << endl;

        stmt = conn->createStatement(query);

        try{
            stmt->executeUpdate();
        } catch(SQLException ex){
            cout<<"Exception thrown for insert"<<endl;
            cout<<"Error number: "<<  ex.getErrorCode() << endl;
            cout<<ex.getMessage() << endl;
        }
        conn->terminateStatement(stmt);

        query = "insert into ";
    }
}

void SqlInterface::customerInsert(vector<CustomerContainer> container2, string table)
{
    int value0;
    string value1;
    string value2;
    string value3;
    string value4;
    int value5;
    string value6;
    string value7;
    string value8;
    string query = "insert into ";
    string buffer1;
    string buffer2;

    for(unsigned int j = 0; j < container2.size(); j++){
        value0 = container2[j].getCarId();
        value1 = container2[j].getFirstName();
        value2 = container2[j].getLastName();
        value3 = container2[j].getAddress();
        value4 = container2[j].getState();
        value5 = container2[j].getZip();
        value6 = container2[j].getDeliveryDate();
        value7 = container2[j].getScheduledMaintenance();
        value8 = container2[j].getUnscheduledRepairs();

        stringstream ss;
        ss << value0;
        buffer1 = ss.str();
        stringstream ss2;
        ss2 << value5;
        buffer2 = ss2.str();
        query = query + table + " values (" + buffer1 + ", " + "'" + value1 + "', '" +  value2 + "', '"
                + value3 + "', '" + value4 + "', " + buffer2 + ", '" + value6
                + "', '" + value7 + "', '" + value8 + "')";
        cout << query << endl;

        stmt = conn->createStatement(query);

        try{
            stmt->executeUpdate();
        } catch(SQLException ex){
            cout<<"Exception thrown for insert"<<endl;
            cout<<"Error number: "<<  ex.getErrorCode() << endl;
            cout<<ex.getMessage() << endl;
        }
        conn->terminateStatement(stmt);

        query = "insert into ";
    }
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
