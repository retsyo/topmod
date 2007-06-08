/****************************************************************************
 **
 **
 ****************************************************************************/
#include <QtGui>

#include "HighgenusMode.hh"

HighgenusMode::HighgenusMode(QWidget *parent, QShortcutManager *sm)
		: QWidget(parent)
{		
	setParent(0);
	mParent = parent;
	
	mAddHoleHandleWidget = new QWidget;
  mAddHoleHandleCVWidget = new QWidget;
  mAddHandleSIWidget = new QWidget;
  mRindModelingScalingWidget = new QWidget;
  mRindModelingThicknessWidget = new QWidget;
  mWireframeModelingWidget = new QWidget;
  mWireframeModeling2Widget = new QWidget;
  mColumnModelingWidget = new QWidget;
	mSierpinskyWidget = new QWidget;
	mMultiFaceHandleWidget = new QWidget;                
	mMengerSpongeWidget = new QWidget;  

	setupAddHoleHandle();
	setupAddHoleHandleCV();
	setupAddHandleSI();
	setupRindModelingScaling();
	setupRindModelingThickness();
	setupWireframeModeling();
	setupWireframeModeling2();
	setupColumnModeling();
	setupSierpinsky();
	setupMultiFaceHandle();
	setupMengerSponge();
	
	//setup the 10 modes for high genus modeling
	mAddHoleHandleAction = new QAction(QIcon(":images/highgenus_addholehandle.png"),tr("Add Hole/Handle"),this);
	mAddHoleHandleAction->setCheckable(true);
	sm->registerAction(mAddHoleHandleAction, "High Genus Operations", "");
	mAddHoleHandleAction->setStatusTip(tr("Enter Add Hole/Handle Mode"));
	mAddHoleHandleAction->setToolTip(tr("Add Hole/Handle Mode"));
	connect(mAddHoleHandleAction, SIGNAL(triggered()), this, SLOT(triggerAddHoleHandle()));
	
	mAddHoleHandleCVAction = new QAction(QIcon(":images/highgenus_addholehandlecv.png"),tr("Add Hole/Handle CV"),this);
	mAddHoleHandleCVAction->setCheckable(true);
	sm->registerAction(mAddHoleHandleCVAction, "High Genus Operations", "");
	mAddHoleHandleCVAction->setStatusTip(tr("Enter Add Hole/Handle CV Mode"));
	mAddHoleHandleCVAction->setToolTip(tr("Add Hole/Handle CV Mode"));
	connect(mAddHoleHandleCVAction, SIGNAL(triggered()), this, SLOT(triggerAddHoleHandleCV()));

	mAddHandleSIAction = new QAction(QIcon(":images/highgenus_addhandlesi.png"),tr("Add Handle SI"),this);
	mAddHandleSIAction->setCheckable(true);
	sm->registerAction(mAddHandleSIAction, "High Genus Operations", "");
	mAddHandleSIAction->setStatusTip(tr("Enter Add Handle (Shape Interpolation) Mode"));
	mAddHandleSIAction->setToolTip(tr("Add Handle (Shape Interpolation) Mode"));
	connect(mAddHandleSIAction, SIGNAL(triggered()), this, SLOT(triggerAddHandleSI()));

	mRindModelingScalingAction = new QAction(QIcon(":images/highgenus_rind.png"),tr("Rind Modeling Scaling"),this);
	mRindModelingScalingAction->setCheckable(true);
	sm->registerAction(mRindModelingScalingAction, "High Genus Operations", "");
	mRindModelingScalingAction->setStatusTip(tr("Enter Rind Modeling Scaling Mode"));
	mRindModelingScalingAction->setToolTip(tr("Rind Modeling Scaling Mode"));
	connect(mRindModelingScalingAction, SIGNAL(triggered()), this, SLOT(triggerRindModelingScaling()));

	mRindModelingThicknessAction = new QAction(QIcon(":images/highgenus_rind.png"),tr("Rind Modeling Thickness"),this);
	mRindModelingThicknessAction->setCheckable(true);
	sm->registerAction(mRindModelingThicknessAction, "High Genus Operations", "");
	mRindModelingThicknessAction->setStatusTip(tr("Enter Rind Modeling Thickness Mode"));
	mRindModelingThicknessAction->setToolTip(tr("Rind Modeling Thickness Mode"));
	connect(mRindModelingThicknessAction, SIGNAL(triggered()), this, SLOT(triggerRindModelingThickness()));

	mWireframeModelingAction = new QAction(QIcon(":images/highgenus_wireframe.png"),tr("Wireframe Modeling"),this);
	mWireframeModelingAction->setCheckable(true);
	sm->registerAction(mWireframeModelingAction, "High Genus Operations", "");
	mWireframeModelingAction->setStatusTip(tr("Enter Wireframe Modeling Mode"));
	mWireframeModelingAction->setToolTip(tr("Wireframe Modeling Mode"));
	connect(mWireframeModelingAction, SIGNAL(triggered()), this, SLOT(triggerWireframeModeling()));

	mWireframeModeling2Action = new QAction(QIcon(":images/highgenus_wireframe.png"),tr("Wireframe Modeling *EXP!!!"),this);
	mWireframeModeling2Action->setCheckable(true);
	sm->registerAction(mWireframeModeling2Action, "High Genus Operations", "");
	mWireframeModeling2Action->setStatusTip(tr("Enter Wireframe Modeling Mode"));
	mWireframeModeling2Action->setToolTip(tr("Wireframe Modeling Mode"));
	connect(mWireframeModeling2Action, SIGNAL(triggered()), this, SLOT(triggerWireframeModeling2()));

	mColumnModelingAction = new QAction(QIcon(":images/highgenus_column.png"),tr("Column Modeling"),this);
	mColumnModelingAction->setCheckable(true);
	sm->registerAction(mColumnModelingAction, "High Genus Operations", "");
	mColumnModelingAction->setStatusTip(tr("Enter Column Modeling Mode"));
	mColumnModelingAction->setToolTip(tr("Column Modeling Mode"));
	connect(mColumnModelingAction, SIGNAL(triggered()), this, SLOT(triggerColumnModeling()));

	mSierpinskyAction = new QAction(QIcon(":images/highgenus_sierpinsky.png"),tr("Sierpinsky"),this);
	mSierpinskyAction->setCheckable(true);
	sm->registerAction(mSierpinskyAction, "High Genus Operations", "");
	mSierpinskyAction->setStatusTip(tr("Enter Sierpinsky Mode"));
	mSierpinskyAction->setToolTip(tr("Sierpinsky Mode"));
	connect(mSierpinskyAction, SIGNAL(triggered()), this, SLOT(triggerSierpinsky()));

	mMultiFaceHandleAction = new QAction(QIcon(":images/highgenus_multifacehandle.png"),tr("Multi-face Handle"),this);
	mMultiFaceHandleAction->setCheckable(true);
	sm->registerAction(mMultiFaceHandleAction, "High Genus Operations", "");
	mMultiFaceHandleAction->setStatusTip(tr("Enter Multi-face Handle Mode"));
	mMultiFaceHandleAction->setToolTip(tr("Multi-face Handle Mode"));
	connect(mMultiFaceHandleAction, SIGNAL(triggered()), this, SLOT(triggerMultiFaceHandle()));

	mMengerSpongeAction = new QAction(QIcon(":images/highgenus_mengersponge.png"),tr("Menger Sponge"),this);
	mMengerSpongeAction->setCheckable(true);
	sm->registerAction(mMengerSpongeAction, "High Genus Operations", "");
	mMengerSpongeAction->setStatusTip(tr("Enter Menger Sponge Mode"));
	mMengerSpongeAction->setToolTip(tr("Menger Sponge Mode"));
	connect(mMengerSpongeAction, SIGNAL(triggered()), this, SLOT(triggerMengerSponge()));
	
}

QMenu* HighgenusMode::getMenu(){
	mHighgenusMenu = new QMenu(tr("High Genus"));
	
	mHighgenusMenu->addAction(mAddHoleHandleAction);
	mHighgenusMenu->addAction(mAddHoleHandleCVAction);
	mHighgenusMenu->addAction(mAddHandleSIAction);
	mHighgenusMenu->addAction(mRindModelingScalingAction); 
	mHighgenusMenu->addAction(mRindModelingThicknessAction);
	mHighgenusMenu->addAction(mWireframeModelingAction); 
	mHighgenusMenu->addAction(mWireframeModeling2Action); 
	mHighgenusMenu->addAction(mColumnModelingAction);	
	mHighgenusMenu->addAction(mSierpinskyAction);
	mHighgenusMenu->addAction(mMultiFaceHandleAction);
	mHighgenusMenu->addAction(mMengerSpongeAction);	
	
	return mHighgenusMenu;
	
}

void HighgenusMode::addActions(QActionGroup *actionGroup, QToolBar *toolBar, QStackedWidget *stackedWidget){
	
	actionGroup->addAction(mAddHoleHandleAction);
	actionGroup->addAction(mAddHoleHandleCVAction);
	actionGroup->addAction(mAddHandleSIAction);
	actionGroup->addAction(mRindModelingScalingAction); 
	actionGroup->addAction(mRindModelingThicknessAction);
	actionGroup->addAction(mWireframeModelingAction); 
	actionGroup->addAction(mWireframeModeling2Action); 
	actionGroup->addAction(mColumnModelingAction);	
	actionGroup->addAction(mSierpinskyAction);
	actionGroup->addAction(mMultiFaceHandleAction);
	actionGroup->addAction(mMengerSpongeAction);
	
	toolBar->addAction(mAddHoleHandleAction);
	toolBar->addAction(mAddHoleHandleCVAction);
	toolBar->addAction(mAddHandleSIAction);
	toolBar->addAction(mRindModelingScalingAction); 
	toolBar->addAction(mRindModelingThicknessAction);
	toolBar->addAction(mWireframeModelingAction); 
	toolBar->addAction(mWireframeModeling2Action); 
	toolBar->addAction(mColumnModelingAction);	
	toolBar->addAction(mSierpinskyAction);
	toolBar->addAction(mMultiFaceHandleAction);
	toolBar->addAction(mMengerSpongeAction);
	
	stackedWidget->addWidget(mAddHoleHandleWidget);
	stackedWidget->addWidget(mAddHoleHandleCVWidget);
	stackedWidget->addWidget(mAddHandleSIWidget);
	stackedWidget->addWidget(mRindModelingScalingWidget); 
	stackedWidget->addWidget(mRindModelingThicknessWidget);
	stackedWidget->addWidget(mWireframeModelingWidget); 
	stackedWidget->addWidget(mWireframeModeling2Widget); 
	stackedWidget->addWidget(mColumnModelingWidget);	
	stackedWidget->addWidget(mSierpinskyWidget);
	stackedWidget->addWidget(mMultiFaceHandleWidget);
	stackedWidget->addWidget(mMengerSpongeWidget);
	
}

void HighgenusMode::triggerAddHoleHandle(){
	
	((MainWindow*)mParent)->setToolOptions(mAddHoleHandleWidget);
	((MainWindow*)mParent)->setMode(MainWindow::ConnectFaceVertices);
}

void HighgenusMode::triggerAddHoleHandleCV(){

	((MainWindow*)mParent)->setToolOptions(mAddHoleHandleCVWidget);
	((MainWindow*)mParent)->setMode(MainWindow::ConnectFaces);	
}

void HighgenusMode::triggerAddHandleSI(){
	
	((MainWindow*)mParent)->setToolOptions(mAddHandleSIWidget);
	((MainWindow*)mParent)->setMode(MainWindow::HermiteConnectFaces);
}

void HighgenusMode::triggerRindModelingScaling(){
	
	((MainWindow*)mParent)->setToolOptions(mRindModelingScalingWidget);
	((MainWindow*)mParent)->setMode(MainWindow::SelectFaceLoop);
	// ((MainWindow*)mParent)->setMode(MainWindow::NormalMode);
}

void HighgenusMode::triggerRindModelingThickness(){
	
	((MainWindow*)mParent)->setToolOptions(mRindModelingThicknessWidget);
	((MainWindow*)mParent)->setMode(MainWindow::SelectFaceLoop);
}

void HighgenusMode::triggerWireframeModeling(){
	
	((MainWindow*)mParent)->setToolOptions(mWireframeModelingWidget);
	((MainWindow*)mParent)->setMode(MainWindow::NormalMode);
}

void HighgenusMode::triggerWireframeModeling2(){
	
	((MainWindow*)mParent)->setToolOptions(mWireframeModeling2Widget);
	((MainWindow*)mParent)->setMode(MainWindow::MultiSelectFace);
}

void HighgenusMode::triggerColumnModeling(){
	
	((MainWindow*)mParent)->setToolOptions(mColumnModelingWidget);
	((MainWindow*)mParent)->setMode(MainWindow::NormalMode);
}

void HighgenusMode::triggerSierpinsky(){
	
	((MainWindow*)mParent)->setToolOptions(mSierpinskyWidget);
	((MainWindow*)mParent)->setMode(MainWindow::NormalMode);
}

void HighgenusMode::triggerMultiFaceHandle(){
	
	((MainWindow*)mParent)->setToolOptions(mMultiFaceHandleWidget);
	((MainWindow*)mParent)->setMode(MainWindow::MultiSelectFace);
}

void HighgenusMode::triggerMengerSponge(){
	
	((MainWindow*)mParent)->setToolOptions(mMengerSpongeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::NormalMode);
}

void HighgenusMode::toggleCrustCleanupFlag(int state)
{
	rindModelingThicknessCleanupCheckBox->setChecked(state);
	rindModelingScalingCleanupCheckBox->setChecked(state);
	
	((MainWindow*)mParent)->toggleCrustCleanupFlag(state);
}

void HighgenusMode::setupAddHoleHandle(){
	
	mAddHoleHandleLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mAddHoleHandleLayout->setMargin(0);
	
	QLabel *addHoleHandleNumSegmentsLabel = new QLabel(tr("Number of Segments"));
	addHoleHandleNumSegmentsSpinBox = new QSpinBox;
	addHoleHandleNumSegmentsSpinBox->setRange(1, 100);
	addHoleHandleNumSegmentsSpinBox->setSingleStep(1);
	addHoleHandleNumSegmentsSpinBox->setValue(4);	
	addHoleHandleNumSegmentsSpinBox->setMaximumSize(75,25);
	connect(addHoleHandleNumSegmentsSpinBox, SIGNAL(valueChanged(int)),
          this, SLOT(numSegmentsValueChanged(int)));
	
	mAddHoleHandleLayout->addWidget(addHoleHandleNumSegmentsLabel);
  mAddHoleHandleLayout->addWidget(addHoleHandleNumSegmentsSpinBox);	
	
	QLabel *addHoleHandleNumSegmentsConnectLabel = new QLabel(tr("# Segments to Connect (0=all)"));
	addHoleHandleNumSegmentsConnectSpinBox = new QSpinBox;
	addHoleHandleNumSegmentsConnectSpinBox->setRange(0, 4);
	addHoleHandleNumSegmentsConnectSpinBox->setSingleStep(1);
	addHoleHandleNumSegmentsConnectSpinBox->setValue(0);	
	addHoleHandleNumSegmentsConnectSpinBox->setMaximumSize(75,25);
	connect(addHoleHandleNumSegmentsConnectSpinBox, SIGNAL(valueChanged(int)),
          this, SLOT(numSegmentsConnectValueChanged(int)));
	
	mAddHoleHandleLayout->addWidget(addHoleHandleNumSegmentsConnectLabel);
  mAddHoleHandleLayout->addWidget(addHoleHandleNumSegmentsConnectSpinBox);	
	
	mAddHoleHandleLayout->addStretch(1);
	mAddHoleHandleWidget->setWindowTitle("Add Hole/Handle");
	mAddHoleHandleWidget->setLayout(mAddHoleHandleLayout);	
	
}

//slot for num segments to reset the max segments range
void HighgenusMode::numSegmentsValueChanged(int value){
	
	((MainWindow*)mParent)->changeNumSegments(value);
	
	addHoleHandleNumSegmentsSpinBox->setValue(value);
	addHoleHandleCVNumSegmentsSpinBox->setValue(value);
	addHandleSINumSegmentsSpinBox->setValue(value);
	
	//set the # segments to connect range on all three hole/handle panels
	addHoleHandleNumSegmentsConnectSpinBox->setRange(0,value);
	addHoleHandleCVNumSegmentsConnectSpinBox->setRange(0,value);
	addHandleSINumSegmentsConnectSpinBox->setRange(0,value);
	
	if (addHoleHandleNumSegmentsConnectSpinBox->value() > value ||
			addHoleHandleCVNumSegmentsConnectSpinBox->value() > value ||
			addHandleSINumSegmentsConnectSpinBox->value() > value) {
				
		addHoleHandleNumSegmentsConnectSpinBox->setValue(value);
		addHoleHandleCVNumSegmentsConnectSpinBox->setValue(value);
		addHandleSINumSegmentsConnectSpinBox->setValue(value);
	}
}

//slot for num segments to set the max segments
void HighgenusMode::numSegmentsConnectValueChanged(int value){
	
	((MainWindow*)mParent)->changeMaxSegments(value);
	
	addHoleHandleNumSegmentsConnectSpinBox->setValue(value);
	addHoleHandleCVNumSegmentsConnectSpinBox->setValue(value);
	addHandleSINumSegmentsConnectSpinBox->setValue(value);	
}

void HighgenusMode::setupAddHoleHandleCV(){
	
	mAddHoleHandleCVLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mAddHoleHandleCVLayout->setMargin(0);

	QLabel *addHoleHandleCVNumSegmentsLabel = new QLabel(tr("Number of Segments"));
	addHoleHandleCVNumSegmentsSpinBox = new QSpinBox;
	addHoleHandleCVNumSegmentsSpinBox->setRange(1, 100);
	addHoleHandleCVNumSegmentsSpinBox->setSingleStep(1);
	addHoleHandleCVNumSegmentsSpinBox->setValue(4);	
	addHoleHandleCVNumSegmentsSpinBox->setMaximumSize(75,25);
	connect(addHoleHandleCVNumSegmentsSpinBox, SIGNAL(valueChanged(int)),
          this, SLOT(numSegmentsValueChanged(int)));

	mAddHoleHandleCVLayout->addWidget(addHoleHandleCVNumSegmentsLabel);
  mAddHoleHandleCVLayout->addWidget(addHoleHandleCVNumSegmentsSpinBox);	
	
	QLabel *addHoleHandleCVNumSegmentsConnectLabel = new QLabel(tr("# Segments to Connect (0=all)"));
	addHoleHandleCVNumSegmentsConnectSpinBox = new QSpinBox;
	addHoleHandleCVNumSegmentsConnectSpinBox->setRange(0, 4);
	addHoleHandleCVNumSegmentsConnectSpinBox->setSingleStep(1);
	addHoleHandleCVNumSegmentsConnectSpinBox->setValue(0);
	addHoleHandleCVNumSegmentsConnectSpinBox->setMaximumSize(75,25);
	connect(addHoleHandleNumSegmentsConnectSpinBox, SIGNAL(valueChanged(int)),
          this, SLOT(numSegmentsConnectValueChanged(int)));
	
	mAddHoleHandleCVLayout->addWidget(addHoleHandleCVNumSegmentsConnectLabel);
  mAddHoleHandleCVLayout->addWidget(addHoleHandleCVNumSegmentsConnectSpinBox);	
	
	mAddHoleHandleCVLayout->addStretch(1);
	mAddHoleHandleCVWidget->setWindowTitle("Add Hole/Handle (Closest Vertex)");
	mAddHoleHandleCVWidget->setLayout(mAddHoleHandleCVLayout);	
}

void HighgenusMode::setupAddHandleSI(){
	
	mAddHandleSILayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mAddHandleSILayout->setMargin(0);
	
	//number of segments
	QLabel *addHandleSINumSegmentsLabel = new QLabel(tr("Number of Segments"));
	addHandleSINumSegmentsSpinBox = new QSpinBox;
	addHandleSINumSegmentsSpinBox->setRange(1, 100);
	addHandleSINumSegmentsSpinBox->setSingleStep(1);
	addHandleSINumSegmentsSpinBox->setValue(4);
	addHandleSINumSegmentsSpinBox->setMaximumSize(75,25);
	connect(addHandleSINumSegmentsSpinBox, SIGNAL(valueChanged(int)),
          this, SLOT(numSegmentsValueChanged(int)));

	mAddHandleSILayout->addWidget(addHandleSINumSegmentsLabel);
  mAddHandleSILayout->addWidget(addHandleSINumSegmentsSpinBox);	
	
	//number of segments to connect
	QLabel *addHandleSINumSegmentsConnectLabel = new QLabel(tr("# Segments to Connect (0=all)"));
	addHandleSINumSegmentsConnectSpinBox = new QSpinBox;
	addHandleSINumSegmentsConnectSpinBox->setRange(0, 4);
	addHandleSINumSegmentsConnectSpinBox->setSingleStep(1);
	addHandleSINumSegmentsConnectSpinBox->setValue(0);
	addHandleSINumSegmentsConnectSpinBox->setMaximumSize(75,25);
	connect(addHoleHandleNumSegmentsConnectSpinBox, SIGNAL(valueChanged(int)),
          this, SLOT(numSegmentsConnectValueChanged(int)));
	
	mAddHandleSILayout->addWidget(addHandleSINumSegmentsConnectLabel);
  mAddHandleSILayout->addWidget(addHandleSINumSegmentsConnectSpinBox);
	
	//weight 1
	QLabel *addHandleSIWeight1Label = new QLabel(tr("Weight 1"));
	QDoubleSpinBox *addHandleSIWeight1SpinBox = new QDoubleSpinBox;
	addHandleSIWeight1SpinBox->setRange(-100.0, 100.0);
	addHandleSIWeight1SpinBox->setSingleStep(0.1);
	addHandleSIWeight1SpinBox->setValue(5.0);
	addHandleSIWeight1SpinBox->setDecimals(1);
	addHandleSIWeight1SpinBox->setMaximumSize(75,25);
	connect(addHandleSIWeight1SpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeWeight1(double)));
	
	mAddHandleSILayout->addWidget(addHandleSIWeight1Label);
  mAddHandleSILayout->addWidget(addHandleSIWeight1SpinBox);
	
	//symmetric weights checkbox
	QCheckBox *addHandleSISymmetricWeightsCheckBox = new QCheckBox(tr("Symmetric Weights"),this);
	addHandleSISymmetricWeightsCheckBox->setChecked(Qt::Checked);
	connect(addHandleSISymmetricWeightsCheckBox, SIGNAL(stateChanged(int)),
          this, SLOT(toggleSymmetricWeightsFlag(int)));
				

	mAddHandleSILayout->addWidget(addHandleSISymmetricWeightsCheckBox);
	
	//weight 2 - must be disabled when the checkbox is unchecked...
	QLabel *addHandleSIWeight2Label = new QLabel(tr("Weight 2:"));
	addHandleSIWeight2SpinBox = new QDoubleSpinBox;
	addHandleSIWeight2SpinBox->setRange(-100.0, 100.0);
	addHandleSIWeight2SpinBox->setSingleStep(0.1);
	addHandleSIWeight2SpinBox->setValue(5.0);
	addHandleSIWeight2SpinBox->setDecimals(1);
	addHandleSIWeight2SpinBox->setMaximumSize(75,25);
	addHandleSIWeight2SpinBox->setEnabled(false);
	
	connect(addHandleSIWeight2SpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeWeight2(double)));

	mAddHandleSILayout->addWidget(addHandleSIWeight2Label);
  mAddHandleSILayout->addWidget(addHandleSIWeight2SpinBox);

	//add twists?
	QLabel *addHandleSITwistsConnectLabel = new QLabel(tr("Extra Twists:"));
	addHandleSITwistsConnectSpinBox = new QSpinBox;
	addHandleSITwistsConnectSpinBox->setRange(0, 100);
	addHandleSITwistsConnectSpinBox->setSingleStep(1);
	addHandleSITwistsConnectSpinBox->setValue(0);	
	addHandleSITwistsConnectSpinBox->setMaximumSize(75,25);
	connect(addHandleSITwistsConnectSpinBox, SIGNAL(valueChanged(int)),
          ((MainWindow*)mParent), SLOT(changeExtraTwists(int)));
	
	mAddHandleSILayout->addWidget(addHandleSITwistsConnectLabel);
  mAddHandleSILayout->addWidget(addHandleSITwistsConnectSpinBox);
	mAddHandleSILayout->addStretch(1);
	mAddHandleSIWidget->setWindowTitle("Add Handle (Shape Interpolation)");
	mAddHandleSIWidget->setLayout(mAddHandleSILayout);	
	
}

void HighgenusMode::toggleSymmetricWeightsFlag(int state){
	
	((MainWindow*)mParent)->toggleSymmetricWeightsFlag(state);
	
	if (state){
		addHandleSIWeight2SpinBox->setEnabled(false);
	}
	else {
		addHandleSIWeight2SpinBox->setEnabled(true);
	}
}

void HighgenusMode::setupRindModelingScaling(){
	
	mRindModelingScalingLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mRindModelingScalingLayout->setMargin(0);

	//scale factor - 0.00-10.00
	QLabel *rindModelingScalingLabel = new QLabel(tr("Scale:"));
	QDoubleSpinBox *rindModelingScalingSpinBox = new QDoubleSpinBox;
	rindModelingScalingSpinBox->setRange(0.0, 10.0);
	rindModelingScalingSpinBox->setSingleStep(0.01);
	rindModelingScalingSpinBox->setValue(0.9);
	rindModelingScalingSpinBox->setDecimals(2);
	rindModelingScalingSpinBox->setMaximumSize(75,25);
	connect(rindModelingScalingSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeCrustScaleFactor(double)));

	mRindModelingScalingLayout->addWidget(rindModelingScalingLabel);
  mRindModelingScalingLayout->addWidget(rindModelingScalingSpinBox);
	
	//symmetric weights checkbox
	rindModelingScalingCleanupCheckBox = new QCheckBox(tr("Cleanup when peeling"),this);
	rindModelingScalingCleanupCheckBox->setChecked(Qt::Unchecked);
	connect(rindModelingScalingCleanupCheckBox, SIGNAL(stateChanged(int)),
          this, SLOT(toggleCrustCleanupFlag(int)));

	mRindModelingScalingLayout->addWidget(rindModelingScalingCleanupCheckBox);
	//create crust button
	QPushButton *rindModelingScalingCreateCrustButton = new QPushButton("Create Crust", this);
	connect(rindModelingScalingCreateCrustButton, SIGNAL(clicked()),
          // ((MainWindow*)mParent), SLOT(crust_modeling1())); //crust_modeling3
          ((MainWindow*)mParent), SLOT(crustModeling4()));

	mRindModelingScalingLayout->addWidget(rindModelingScalingCreateCrustButton);	
	//set layout and add stretch
	mRindModelingScalingLayout->addStretch(1);
	mRindModelingScalingWidget->setWindowTitle("Rind Modeling (Scaling)");
	mRindModelingScalingWidget->setLayout(mRindModelingScalingLayout);	
}

void HighgenusMode::setupRindModelingThickness(){

	mRindModelingThicknessLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mRindModelingThicknessLayout->setMargin(0);
	
	//thickness
	QLabel *rindModelingThicknessLabel = new QLabel(tr("Thickness:"));
	QDoubleSpinBox *rindModelingThicknessSpinBox = new QDoubleSpinBox;
	rindModelingThicknessSpinBox->setRange(-1.0, 1.0);
	rindModelingThicknessSpinBox->setSingleStep(0.01);
	rindModelingThicknessSpinBox->setValue(0.5);
	rindModelingThicknessSpinBox->setDecimals(2);
	rindModelingThicknessSpinBox->setMaximumSize(75,25);
	connect(rindModelingThicknessSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeCrustThickness(double)));
	
	mRindModelingThicknessLayout->addWidget(rindModelingThicknessLabel);
  mRindModelingThicknessLayout->addWidget(rindModelingThicknessSpinBox);
	
	//symmetric weights checkbox
	rindModelingThicknessCleanupCheckBox = new QCheckBox(tr("Cleanup when peeling"),this);
	rindModelingThicknessCleanupCheckBox->setChecked(Qt::Unchecked);
	connect(rindModelingThicknessCleanupCheckBox, SIGNAL(stateChanged(int)),
          this, SLOT(toggleCrustCleanupFlag(int)));

	mRindModelingThicknessLayout->addWidget(rindModelingThicknessCleanupCheckBox);
	//create crust button
	QPushButton *rindModelingThicknessCreateButton = new QPushButton("Create Crust", this);
	connect(rindModelingThicknessCreateButton, SIGNAL(clicked()),
          ((MainWindow*)mParent), SLOT(crustModeling3()));

	mRindModelingThicknessLayout->addWidget(rindModelingThicknessCreateButton);	
	//set layout and add stretch
	mRindModelingThicknessLayout->addStretch(1);
	mRindModelingThicknessWidget->setWindowTitle("Rind Modeling (Thickness)");
	mRindModelingThicknessWidget->setLayout(mRindModelingThicknessLayout);
}

void HighgenusMode::setupWireframeModeling(){
	
	mWireframeModelingLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mWireframeModelingLayout->setMargin(0);
	
	//thickness
	QLabel *wireframeModelingThicknessLabel = new QLabel(tr("Thickness:"));
	QDoubleSpinBox *wireframeModelingThicknessSpinBox = new QDoubleSpinBox;
	wireframeModelingThicknessSpinBox->setRange(0.0, 1.0);
	wireframeModelingThicknessSpinBox->setSingleStep(0.01);
	wireframeModelingThicknessSpinBox->setValue(0.25);
	wireframeModelingThicknessSpinBox->setDecimals(2);
	wireframeModelingThicknessSpinBox->setMaximumSize(75,25);
	connect(wireframeModelingThicknessSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeWireframeThickness(double)));
	
	mWireframeModelingLayout->addWidget(wireframeModelingThicknessLabel);
  mWireframeModelingLayout->addWidget(wireframeModelingThicknessSpinBox);
	//create wireframe button
	QPushButton *wireframeModelingCreateButton = new QPushButton("Create Wireframe", this);
	connect(wireframeModelingCreateButton, SIGNAL(clicked()),
          ((MainWindow*)mParent), SLOT(makeWireframe()));
	mWireframeModelingLayout->addWidget(wireframeModelingCreateButton);	
	//set layout and add stretch
	mWireframeModelingLayout->addStretch(1);
	mWireframeModelingWidget->setWindowTitle("Wireframe Modeling");
	mWireframeModelingWidget->setLayout(mWireframeModelingLayout);
}

void HighgenusMode::setupWireframeModeling2(){
	
	mWireframeModeling2Layout = new QBoxLayout(QBoxLayout::LeftToRight);
	mWireframeModeling2Layout->setMargin(0);
	
	//thickness
	QLabel *WireframeModeling2ThicknessLabel = new QLabel(tr("Thickness:"));
	QDoubleSpinBox *WireframeModeling2ThicknessSpinBox = new QDoubleSpinBox;
	WireframeModeling2ThicknessSpinBox->setRange(0.0, 1.0);
	WireframeModeling2ThicknessSpinBox->setSingleStep(0.01);
	WireframeModeling2ThicknessSpinBox->setValue(0.25);
	WireframeModeling2ThicknessSpinBox->setDecimals(2);
	WireframeModeling2ThicknessSpinBox->setMaximumSize(75,25);
	connect(WireframeModeling2ThicknessSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeWireframeThickness(double)));
	
	mWireframeModeling2Layout->addWidget(WireframeModeling2ThicknessLabel);
  mWireframeModeling2Layout->addWidget(WireframeModeling2ThicknessSpinBox);
	//create wireframe button
	QPushButton *WireframeModeling2CreateButton = new QPushButton("Create Wireframe", this);
	connect(WireframeModeling2CreateButton, SIGNAL(clicked()),
          ((MainWindow*)mParent), SLOT(makeWireframe2()));
	mWireframeModeling2Layout->addWidget(WireframeModeling2CreateButton);	
	//set layout and add stretch
	mWireframeModeling2Layout->addStretch(1);
	mWireframeModeling2Widget->setWindowTitle("Wireframe Modeling ***EXP!!");
	mWireframeModeling2Widget->setLayout(mWireframeModeling2Layout);
}

void HighgenusMode::setupColumnModeling(){
	
	mColumnModelingLayout = new QBoxLayout(QBoxLayout::LeftToRight);	
	mColumnModelingLayout->setMargin(0);
	//thickness
	QLabel *columnModelingThicknessLabel = new QLabel(tr("Thickness:"));
	QDoubleSpinBox *columnModelingThicknessSpinBox = new QDoubleSpinBox;
	columnModelingThicknessSpinBox->setRange(0.0, 1.0);
	columnModelingThicknessSpinBox->setSingleStep(0.01);
	columnModelingThicknessSpinBox->setValue(0.25);
	columnModelingThicknessSpinBox->setDecimals(2);
	columnModelingThicknessSpinBox->setMaximumSize(75,25);
	connect(columnModelingThicknessSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeColumnThickness(double)));
	
	mColumnModelingLayout->addWidget(columnModelingThicknessLabel);
  mColumnModelingLayout->addWidget(columnModelingThicknessSpinBox);
	//number of segments
	QLabel *columnModelingNumSegmentsLabel = new QLabel(tr("Number of Segments:"));
	QSpinBox *columnModelingNumSegmentsSpinBox = new QSpinBox;
	columnModelingNumSegmentsSpinBox->setRange(4, 100);
	columnModelingNumSegmentsSpinBox->setSingleStep(1);
	columnModelingNumSegmentsSpinBox->setValue(0);
	columnModelingNumSegmentsSpinBox->setMaximumSize(75,25);
	connect(columnModelingNumSegmentsSpinBox, SIGNAL(valueChanged(int)),
          ((MainWindow*)mParent), SLOT(changeColumnSegments(int)));

	mColumnModelingLayout->addWidget(columnModelingNumSegmentsLabel);
  mColumnModelingLayout->addWidget(columnModelingNumSegmentsSpinBox);
	//create column button
	QPushButton *columnModelingCreateButton = new QPushButton("Create Wireframe with Columns", this);
	connect(columnModelingCreateButton, SIGNAL(clicked()),
          ((MainWindow*)mParent), SLOT(makeWireframeWithColumns()));
	mColumnModelingLayout->addWidget(columnModelingCreateButton);	
	//set layout and add stretch
	mColumnModelingLayout->addStretch(1);
	mColumnModelingWidget->setWindowTitle("Column Modeling");
	mColumnModelingWidget->setLayout(mColumnModelingLayout);	
}

void HighgenusMode::setupSierpinsky(){
	
	mSierpinskyLayout = new QBoxLayout(QBoxLayout::LeftToRight);	
	mSierpinskyLayout->setMargin(0);
	
	//create column button
	QPushButton *sierpinskyButton = new QPushButton("Create Sierpinsky Tetrahedra", this);
	connect(sierpinskyButton, SIGNAL(clicked()),
          ((MainWindow*)mParent), SLOT(multiConnectMidpoints()));

	mSierpinskyLayout->addWidget(sierpinskyButton);
	
	mSierpinskyLayout->addStretch(1);
	mSierpinskyWidget->setWindowTitle("Sierpinsky Tetrahedra");
	mSierpinskyWidget->setLayout(mSierpinskyLayout);	
}

void HighgenusMode::setupMultiFaceHandle(){
	
	mMultiFaceHandleLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mMultiFaceHandleLayout->setMargin(0);
		
	QGroupBox *multiFaceAlgorithmGroupBox = new QGroupBox(tr("Use Convex Hull Algorithm"));
	multiFaceAlgorithmGroupBox->setCheckable(true);
	multiFaceAlgorithmGroupBox->setChecked(false);
	
	mMultiFaceAlgorithmLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mMultiFaceAlgorithmLayout->setMargin(0);
	multiFaceAlgorithmGroupBox->setAlignment(Qt::AlignLeft);

	connect(multiFaceAlgorithmGroupBox, SIGNAL(toggled(bool)),
	          this, SLOT(changeMultiFaceAlgorithm(bool)));
	
	//scaling
	multiFaceHandleScaleLabel = new QLabel(tr("Scale Factor:"));
	multiFaceHandleScaleSpinBox = new QDoubleSpinBox;
	multiFaceHandleScaleSpinBox->setRange(0.0, 5.0);
	multiFaceHandleScaleSpinBox->setSingleStep(0.01);
	multiFaceHandleScaleSpinBox->setValue(1.0);
	multiFaceHandleScaleSpinBox->setDecimals(2);
	multiFaceHandleScaleSpinBox->setMaximumSize(75,25);
	connect(multiFaceHandleScaleSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeMultiFaceHandleScaleFactor(double)));
	
	mMultiFaceAlgorithmLayout->addWidget(multiFaceHandleScaleLabel);
  mMultiFaceAlgorithmLayout->addWidget(multiFaceHandleScaleSpinBox);
	
	//extrude distance
	multiFaceHandleExtrudeDistanceLabel = new QLabel(tr("Extrude Distance Factor:"));
	multiFaceHandleExtrudeDistanceSpinBox = new QDoubleSpinBox;
	multiFaceHandleExtrudeDistanceSpinBox->setRange(-2.0, 2.0);
	multiFaceHandleExtrudeDistanceSpinBox->setSingleStep(0.1);
	multiFaceHandleExtrudeDistanceSpinBox->setValue(0.5);
	multiFaceHandleExtrudeDistanceSpinBox->setDecimals(2);
	multiFaceHandleExtrudeDistanceSpinBox->setMaximumSize(75,25);
	connect(multiFaceHandleExtrudeDistanceSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeMultiFaceHandleExtrudeDist(double)));
	
	mMultiFaceAlgorithmLayout->addWidget(multiFaceHandleExtrudeDistanceLabel);
  mMultiFaceAlgorithmLayout->addWidget(multiFaceHandleExtrudeDistanceSpinBox);
	
	//use max. offsets
	multiFaceHandleMaxOffsetsCheckBox = new QCheckBox(tr("Use max offsets"),this);
	connect(multiFaceHandleMaxOffsetsCheckBox, SIGNAL(stateChanged(int)),
          this, SLOT(toggleMultiFaceHandleUseMaxOffsetFlag(int)));

	mMultiFaceAlgorithmLayout->addWidget(multiFaceHandleMaxOffsetsCheckBox);

	multiFaceAlgorithmGroupBox->setLayout(mMultiFaceAlgorithmLayout);
	
	//add the groupbox to the multiface layout
	mMultiFaceHandleLayout->addWidget(multiFaceAlgorithmGroupBox);

	QPushButton *multiFaceHandleButton = new QPushButton("Connect Selected Faces", this);
	connect(multiFaceHandleButton, SIGNAL(clicked()),
          ((MainWindow*)mParent), SLOT(createMultiFaceHandle()));

	mMultiFaceHandleLayout->addWidget(multiFaceHandleButton);
	mMultiFaceHandleLayout->addStretch(1);
	mMultiFaceHandleWidget->setWindowTitle("Multi-Face Handle");
	mMultiFaceHandleWidget->setLayout(mMultiFaceHandleLayout);
}

void HighgenusMode::toggleMultiFaceHandleUseMaxOffsetFlag(int state){
	
	((MainWindow*)mParent)->toggleMultiFaceHandleUseMaxOffsetFlag(state);
	
	if (state){
		multiFaceHandleExtrudeDistanceSpinBox->setEnabled(false);
		multiFaceHandleExtrudeDistanceLabel->setEnabled(false);
	}
	else {
		multiFaceHandleExtrudeDistanceLabel->setEnabled(true);
		multiFaceHandleExtrudeDistanceSpinBox->setEnabled(true);
	}
}

void HighgenusMode::changeMultiFaceAlgorithm(bool on){
	
	if (!on) {
		((MainWindow*)mParent)->mfh_use_closest_edge_algo();	
		// //set all three widgets to be disabled
		// multiFaceHandleScaleLabel->setEnabled(false);
		// multiFaceHandleExtrudeDistanceLabel->setEnabled(false);
		// multiFaceHandleExtrudeDistanceSpinBox->setEnabled(false);
		// multiFaceHandleMaxOffsetsCheckBox->setEnabled(false);
		// multiFaceHandleScaleSpinBox->setEnabled(false);		
		
	}
	else { 		
		((MainWindow*)mParent)->mfh_use_convex_hull_algo();	
		// 
		// multiFaceHandleScaleLabel->setEnabled(false);
		// multiFaceHandleScaleSpinBox->setEnabled(true);
		// multiFaceHandleMaxOffsetsCheckBox->setEnabled(true);
		// 
		// //check if the checkbox is checked first or not, then enable widgets accordingly
		// if (multiFaceHandleMaxOffsetsCheckBox->checkState() == Qt::Checked){
		// 	multiFaceHandleExtrudeDistanceLabel->setEnabled(true);
		// 	multiFaceHandleExtrudeDistanceSpinBox->setEnabled(true);
		// }
	}
}

void HighgenusMode::setupMengerSponge(){
	
	mMengerSpongeLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	mMengerSpongeLayout->setMargin(0);
	
	//thickness
	QLabel *mengerSpongeThicknessLabel = new QLabel(tr("Thickness:"));
	QDoubleSpinBox *mengerSpongeThicknessSpinBox = new QDoubleSpinBox;
	mengerSpongeThicknessSpinBox->setRange(0.01, 1.0);
	mengerSpongeThicknessSpinBox->setSingleStep(0.01);
	mengerSpongeThicknessSpinBox->setValue(0.67);
	mengerSpongeThicknessSpinBox->setDecimals(2);
	mengerSpongeThicknessSpinBox->setMaximumSize(75,25);
	connect(mengerSpongeThicknessSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeMengerSpongeThickness(double)));

	mMengerSpongeLayout->addWidget(mengerSpongeThicknessLabel);
  mMengerSpongeLayout->addWidget(mengerSpongeThicknessSpinBox);	
	
	//threshold
	QLabel *mengerSpongeThresholdLabel = new QLabel(tr("Edge Collapse Threshold Factor:"));
	QDoubleSpinBox *mengerSpongeThresholdSpinBox = new QDoubleSpinBox;
	mengerSpongeThresholdSpinBox->setRange(0.0, 10.0);
	mengerSpongeThresholdSpinBox->setSingleStep(0.1);
	mengerSpongeThresholdSpinBox->setValue(0.0);
	mengerSpongeThresholdSpinBox->setDecimals(1);
	mengerSpongeThresholdSpinBox->setMaximumSize(75,25);
	connect(mengerSpongeThresholdSpinBox, SIGNAL(valueChanged(double)),
          ((MainWindow*)mParent), SLOT(changeMengerSpongeCollapseThreshold(double)));

	mMengerSpongeLayout->addWidget(mengerSpongeThresholdLabel);
  mMengerSpongeLayout->addWidget(mengerSpongeThresholdSpinBox);	
	
	//fractional thickness checkbox
	QCheckBox *mengerSpongFractionalThicknessCheckBox = new QCheckBox(tr("Fractional Thickness"),this);
	connect(mengerSpongFractionalThicknessCheckBox, SIGNAL(stateChanged(int)),
          ((MainWindow*)mParent), SLOT(toggleMengerSpongeFractionalThicknessFlag(int)));

	mMengerSpongeLayout->addWidget(mengerSpongFractionalThicknessCheckBox);
	
	//create menger sponge button
	QPushButton *mengerSpongeButton = new QPushButton("Create Menger Sponge", this);
	connect(mengerSpongeButton, SIGNAL(clicked()),
          ((MainWindow*)mParent), SLOT(createSponge()));

	mMengerSpongeLayout->addWidget(mengerSpongeButton);	
	mMengerSpongeLayout->addStretch(1);
	mMengerSpongeWidget->setWindowTitle("Menger Sponge");
	mMengerSpongeWidget->setLayout(mMengerSpongeLayout);
}