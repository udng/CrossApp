
#include "ListViewTest.h"

CDListViewTest::CDListViewTest()
{
    tempList.clear();
    tempList.push_back("1");
    tempList.push_back("2");
    tempList.push_back("3");
    tempList.push_back("4");
    tempList.push_back("5");
    tempList.push_back("6");
    tempList.push_back("7");
    tempList.push_back("8");
    tempList.push_back("9");
    tempList.push_back("10");
    tempList.push_back("11");
    tempList.push_back("12");
    tempList.push_back("13");
    tempList.push_back("14");
    tempList.push_back("15");
    tempList.push_back("16");
    tempList.push_back("17");
    tempList.push_back("18");
    tempList.push_back("19");
    tempList.push_back("20");
}

CDListViewTest::~CDListViewTest()
{

}

bool CDListViewTest::init()
{
    CAListView* listView = CAListView::createWithLayout(DRectLayout(0,0,0,100,DRectLayout::L_R_T_H));
    listView->setListViewDelegate(this);
    listView->setListViewDataSource(this);
    listView->setAllowsSelection(true);
    listView->setAllowsMultipleSelection(false);
    listView->setListViewOrientation(CAListViewOrientationHorizontal);
    //listView->setShowsHorizontalScrollIndicator(false);
    listView->setShowsScrollIndicators(false);
    
    listView->setSeparatorColor(CAColor_clear);
    this->addSubview(listView);
    return true;
}

CDListViewTest* CDListViewTest::createWithLayout(const CrossApp::DRectLayout &layout)
{
    CDListViewTest* pRet = new CDListViewTest();
    if (pRet && pRet->initWithLayout(layout))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

void CDListViewTest::listViewDidSelectCellAtIndex(CAListView *listView, unsigned int index)
{
    
}

void CDListViewTest::listViewDidDeselectCellAtIndex(CAListView *listView, unsigned int index)
{
    
}

unsigned int CDListViewTest::numberOfIndex(CAListView *listView)
{
    return tempList.size();
}

unsigned int CDListViewTest::listViewHeightForIndex(CAListView *listView, unsigned int index)
{
    return 150;
}

CAListViewCell* CDListViewTest::listViewCellAtIndex(CAListView *listView, const DSize& cellSize, unsigned int index)
{
    CAListViewCell* cell = (CAListViewCell*)listView->dequeueReusableCellWithIdentifier("ListViewCell");
    if (!cell)
    {
        cell = CAListViewCell::create("ListViewCell");
        CALabel* test = CALabel::createWithLayout(DRectLayout(0,0,0,0,DRectLayout::L_R_T_B));
        test->setColor(ccc4(51, 204, 255, 255));
        test->setTextAlignment(CATextAlignmentCenter);
        test->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
        test->setFontSize(28);
        test->setTag(100);
        cell->addSubview(test);
    }
    char temptext[10];
    sprintf(temptext, "cell-%d",index);
    CALabel* test = (CALabel*)cell->getSubviewByTag(100);
    test->setText(temptext);
    
    return cell;
}

ListViewTest::ListViewTest()
{
    CADrawerController* drawer = (CADrawerController*)CAApplication::getApplication()->getRootWindow()->getRootViewController();
    drawer->setTouchMoved(false);
}

ListViewTest::~ListViewTest()
{
    CADrawerController* drawer = (CADrawerController*)CAApplication::getApplication()->getRootWindow()->getRootViewController();
    drawer->setTouchMoved(true);
}

void ListViewTest::viewDidLoad()
{
    CDListViewTest* listview1 = CDListViewTest::createWithLayout(DRectLayout(0,0,0,100,DRectLayout::L_R_T_H));
    listview1->init();//不调用 init
    this->getView()->addSubview(listview1);
    
    p_ListView = CAListView::createWithLayout(DRectLayout(0,0,100,0,DRectLayout::L_R_T_B));
    p_ListView->setListViewDelegate(this);
    p_ListView->setListViewDataSource(this);
    p_ListView->setAllowsSelection(true);
    p_ListView->setAllowsMultipleSelection(false);
    p_ListView->setListViewOrientation(CAListViewOrientationVertical);
    p_ListView->setShowsScrollIndicators(true);
    
    p_ListView->setSeparatorColor(CAColor_gray);
    this->getView()->addSubview(p_ListView);
    
}
void ListViewTest::viewDidUnload()
{
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

void ListViewTest::listViewDidSelectCellAtIndex(CAListView *listView, unsigned int index)
{
    
}

void ListViewTest::listViewDidDeselectCellAtIndex(CAListView *listView, unsigned int index)
{
    
}

unsigned int ListViewTest::numberOfIndex(CAListView *listView)
{
    return 30;
}

unsigned int ListViewTest::listViewHeightForIndex(CAListView *listView, unsigned int index)
{
    return 100;
}

CAListViewCell* ListViewTest::listViewCellAtIndex(CAListView *listView, const DSize& cellSize, unsigned int index)
{
    DSize _size = cellSize;
    CAListViewCell* cell = (CAListViewCell*)listView->dequeueReusableCellWithIdentifier("ListViewCell");
    if (cell==NULL)
    {
        cell = CAListViewCell::create("ListViewCell");
        
        CALabel* test = CALabel::createWithLayout(DRectLayout(0,500,0,0,DRectLayout::L_R_T_B));
        test->setColor(ccc4(51, 204, 255, 255));
        test->setTextAlignment(CATextAlignmentCenter);
        test->setVerticalTextAlignmet(CAVerticalTextAlignmentCenter);
        test->setFontSize(28);
        test->setTag(100);
        cell->addSubview(test);
        
        CAButton* btn = CAButton::createWithLayout(DRectLayout(600,50,25,25,DRectLayout::L_R_T_B), CAButtonTypeSquareRect);
        btn->setTitleForState(CAControlStateNormal, "btn");
        btn->setTag(200);
        cell->addSubview(btn);
        btn->setTouchEventScrollHandOverToSuperview(false);
    }
    char temptext[10];
    sprintf(temptext, "cell-%d",index);
    CALabel* test = (CALabel*)cell->getSubviewByTag(100);
    test->setText(temptext);
    
    return cell;
}

