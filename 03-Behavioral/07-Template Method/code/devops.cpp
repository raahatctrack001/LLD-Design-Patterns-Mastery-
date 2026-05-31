#include<iostream>

using namespace std;


/*
==================================================
TEMPLATE METHOD PATTERN
==================================================

Real World Example:
-------------------

CI/CD Deployment Pipeline

Fixed Workflow:
1. Build Project
2. Run Tests
3. Deploy Application
4. Send Notification

Different deployment types:
- Staging Deployment
- Production Deployment

Only some steps vary.
==================================================
*/


/*
==================================================
ABSTRACT TEMPLATE CLASS
==================================================
*/

class DeploymentPipeline {

public:

    /*
    ==============================================
    TEMPLATE METHOD
    ==============================================
    */

    void executePipeline() {

        build();

        runTests();

        deploy();

        sendNotification();
    }


    virtual void build() {

        cout
            << "Building application..."
            << endl;
    }


    virtual void runTests() {

        cout
            << "Running automated tests..."
            << endl;
    }


    virtual void deploy() = 0;


    virtual void sendNotification() {

        cout
            << "Sending deployment notification..."
            << endl;
    }


    virtual ~DeploymentPipeline() {}
};



/*
==================================================
CONCRETE IMPLEMENTATION
==================================================
*/

class StagingDeployment
    : public DeploymentPipeline {

public:

    void deploy() override {

        cout
            << "Deploying to STAGING server..."
            << endl;
    }
};



class ProductionDeployment
    : public DeploymentPipeline {

public:

    void runTests() override {

        cout
            << "Running advanced production tests..."
            << endl;
    }

    void deploy() override {

        cout
            << "Deploying to PRODUCTION server..."
            << endl;
    }

    void sendNotification() override {

        cout
            << "Sending Slack + Email alerts..."
            << endl;
    }
};



/*
==================================================
CLIENT
==================================================
*/

int main() {

    cout
        << "====== STAGING PIPELINE ======"
        << endl;

    DeploymentPipeline* staging =
        new StagingDeployment();

    staging->executePipeline();

    cout << endl;



    cout
        << "====== PRODUCTION PIPELINE ======"
        << endl;

    DeploymentPipeline* production =
        new ProductionDeployment();

    production->executePipeline();



    delete staging;
    delete production;

    return 0;
}