

#include <Wt/WApplication>
#include <Wt/WNavigationBar>
#include <Wt/WBootstrapTheme>
#include <Wt/WImage>
#include <Wt/WStackedWidget>
#include <Wt/WMenu>
#include <Wt/WPushButton>
#include <Wt/WLineEdit>
#include <Wt/WStandardItemModel>
#include <Wt/WTableView>
#include <Wt/WTable>
#include <Wt/WTable>

#include <Wt/WTable>


#include <iostream>




using namespace std; 
using namespace Wt;



class HMIApplication : public WApplication
{
  public:
    WLineEdit *picsNum_LE;
    HMIApplication(const WEnvironment &env);
    Wt::WText *specialValue;
    string sharedVal = "1";


  private:
    // Main Tabs
    Wt::WWidget *CapturePage();
    Wt::WWidget *AnalysisPage();

    // Functions that connect the pages to Droplet Measurement
    void TakePicture();
    void InitCamera();

    // Functions that deal with Streaming

    Wt::WTable *capturePageTable;
};

////////////////////////////////////////////////////
// Below is the section that creates the GUI layout
////////////////////////////////////////////////////
HMIApplication::HMIApplication(const WEnvironment &env) : WApplication(env)
{

    //WApplication *app = WApplication::instance();
    //app->enableUpdates();

    // TODO: Bootsrap is not found in Mazlite_Dropsizer/Resources/themes/bootstrap/2
    // load the default bootstrap3 (sub-)theme
    useStyleSheet("/Resources/CSS/bootstrap.css");
    useStyleSheet("/Resources/CSS/bootstrap.min.css");
    useStyleSheet("/Resources/CSS/bootstrap-responsive.css");
    useStyleSheet("/Resources/CSS/bootstrap-responsive.min.css");

    // load text bundles (for the tr() function)
    messageResourceBundle().use(appRoot() + "report");
    messageResourceBundle().use(appRoot() + "text");
    messageResourceBundle().use(appRoot() + "src");

    // Add an external style sheet to the application.
    useStyleSheet("/Resources/CSS/CSSexample.css");
    useStyleSheet("/Resources/CSS/everywidget.css");
    useStyleSheet("/Resources/CSS/dragdrop.css");
    useStyleSheet("/Resources/CSS/combostyle.css");
    useStyleSheet("/Resources/CSS/pygments.css");
    useStyleSheet("/Resources/CSS/layout.css");
    useStyleSheet("/Resources/CSS/filedrop.css");

    // application title
    setTitle("WT Examples: Server Updates");

    // Sets theme for app
    setTheme(new WBootstrapTheme());

    specialValue = new WText("0");

    // The main part of the physical layout
    Wt::WContainerWidget *container = new Wt::WContainerWidget(root());

    // Create a navigation bar with a link to a web page.
    Wt::WNavigationBar *navigation = new Wt::WNavigationBar();
    navigation->setTitle("DropSizer");
    navigation->setResponsive(false);
    container->addWidget(navigation);

    // Note that A WNavigationBar consists of one ore more WMenu controls - each working in conjunction with a WStackedWidget to manage its contents.
    Wt::WStackedWidget *navBarContent_CS = new Wt::WStackedWidget();
    navBarContent_CS->addStyleClass("contents");
    container->addWidget(navBarContent_CS);

    // TODO:: Logo disappears when resizing
    Wt::WImage *logo = new Wt::WImage(Wt::WLink("/Resources/Images/logo2.jpg"));
    navigation->addWidget(logo);

    Wt::WMenu *leftMenu = new Wt::WMenu(navBarContent_CS);

    leftMenu->addItem("Capture", CapturePage());
    leftMenu->addItem("Analysis", AnalysisPage());
    navigation->addMenu(leftMenu);
}


Wt::WWidget *HMIApplication::CapturePage()
{
    cout << "*********Capture page. SharedVal is "<<sharedVal<<endl;

    // Create Table to be used for HMI layout of capture page
    capturePageTable = new Wt::WTable();
    capturePageTable->setObjectName("capturePageTable");
    capturePageTable->addStyleClass("table form-inline"); //Adding CSS formatting to table

    Wt::WContainerWidget *container = new Wt::WContainerWidget();
    container->setObjectName("CapturePage"); 
    container->addWidget(capturePageTable);

    // Add items to Capture section
    capturePageTable->elementAt(0, 1)->addWidget(new Wt::WText("Initialize Camera & Start Capturing Images"));

    // Setting up the init camera button and adding it to the capturePageTable
    WPushButton *initCamera_B = new WPushButton("Initialize Camera");
    initCamera_B->setMargin(5, Left); // TODO: use define variables for margins or percentages
    initCamera_B->setMargin(5, Right);
    initCamera_B->clicked().connect(this, &HMIApplication::InitCamera);
    capturePageTable->elementAt(0, 0)->addWidget(initCamera_B);

    // Setting up the capture images button and adding it to the capturePageTable
    WPushButton *captureImages_B = new WPushButton("Start Capture");
    captureImages_B->setMargin(5, Left);
    captureImages_B->setMargin(5, Right);
    captureImages_B->clicked().connect(this, &HMIApplication::TakePicture);
    capturePageTable->elementAt(0, 0)->addWidget(captureImages_B);


    capturePageTable->elementAt(1, 1)->addWidget(new Wt::WText("Number of Images to Capture (Min:1, Max:500)"));

    picsNum_LE = new Wt::WLineEdit();
    picsNum_LE->setMargin(5, Left);
    picsNum_LE->setMargin(5, Right);
    picsNum_LE->setText("15");
    // TODO: use define variables for above numbers
    capturePageTable->elementAt(1, 0)->addWidget(picsNum_LE);



    // Add items to Flash section
    capturePageTable->elementAt(2, 1)->addWidget(new Wt::WText("Flash Duration"));
    return container;
}



Wt::WWidget *HMIApplication::AnalysisPage()
{
	// Get moments and histogram data to display
	
    Wt::WContainerWidget *container = new Wt::WContainerWidget();
    new Wt::WText("<center><h3> Analysis Results  </h3></center>", container);
    specialValue->setText(sharedVal);
    container->addWidget(specialValue);
    cout << "*********Analysis page. SharedVal is "<<sharedVal<<endl;
    return container;
}



// Function that is called everytime Capture button is clicked
void HMIApplication::TakePicture()
{
    sharedVal ="2";
    specialValue->setText(sharedVal);
    cout<< "*********Take picture. SharedVal is now " << sharedVal <<endl<<endl;
    //WApplication::instance()->triggerUpdate();
}


// Function that is called everytime Capture button is clicked
void HMIApplication::InitCamera()
{
    cout<< "*********Init Camera"<<endl;
}

WApplication *createApplication(const WEnvironment &env)
{
    return new HMIApplication(env);
}

int main (int argc, char * argv[]){
    return WRun(argc, argv, &createApplication);
}
