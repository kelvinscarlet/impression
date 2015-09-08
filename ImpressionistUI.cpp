//
// impressionistUI.h
//
// The user interface part for the program.
//


#include <FL/fl_ask.h>

#include <math.h>

#include "impressionistUI.h"
#include "impressionistDoc.h"

/*
//------------------------------ Widget Examples -------------------------------------------------
Here is some example code for all of the widgets that you may need to add to the 
project.  You can copy and paste these into your code and then change them to 
make them look how you want.  Descriptions for all of the widgets here can be found 
in links on the fltk help session page.

//---------Window/Dialog and Menubar-----------------------------------
	
	//----To install a window--------------------------
	Fl_Window* myWindow = new Fl_Window(600, 300, "MyWindow");
		myWindow->user_data((void*)(this));	// record self to be used by static callback functions
		
		// install menu bar
		myMenubar = new Fl_Menu_Bar(0, 0, 600, 25);
		Fl_Menu_Item ImpressionistUI::myMenuItems[] = {
			{ "&File",		0, 0, 0, FL_SUBMENU },
				{ "&Load...",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load },
				{ "&Save...",	FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save }.
				{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
				{ 0 },
			{ "&Edit",		0, 0, 0, FL_SUBMENU },
				{ "&Copy",FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_copy, (void *)COPY },
				{ "&Cut",	FL_ALT + 'x', (Fl_Callback *)ImpressionistUI::cb_cut, (void *)CUT },
				{ "&Paste",	FL_ALT + 'v', (Fl_Callback *)ImpressionistUI::cb_paste, (void *)PASTE },
				{ 0 },
			{ "&Help",		0, 0, 0, FL_SUBMENU },
				{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
				{ 0 },
			{ 0 }
		};
		myMenubar->menu(myMenuItems);
    m_mainWindow->end();

	//----The window callback--------------------------
	// One of the callbacks
	void ImpressionistUI::cb_load(Fl_Menu_* o, void* v) 
	{	
		ImpressionistDoc *pDoc=whoami(o)->getDocument();

		char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
		if (newfile != NULL) {
			pDoc->loadImage(newfile);
		}
	}


//------------Slider---------------------------------------

	//----To install a slider--------------------------
	Fl_Value_Slider * mySlider = new Fl_Value_Slider(10, 80, 300, 20, "My Value");
	mySlider->user_data((void*)(this));	// record self to be used by static callback functions
	mySlider->type(FL_HOR_NICE_SLIDER);
    mySlider->labelfont(FL_COURIER);
    mySlider->labelsize(12);
	mySlider->minimum(1);
	mySlider->maximum(40);
	mySlider->step(1);
	mySlider->value(m_nMyValue);
	mySlider->align(FL_ALIGN_RIGHT);
	mySlider->callback(cb_MyValueSlides);

	//----The slider callback--------------------------
	void ImpressionistUI::cb_MyValueSlides(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyValue=int( ((Fl_Slider *)o)->value() ) ;
	}
	

//------------Choice---------------------------------------
	
	//----To install a choice--------------------------
	Fl_Choice * myChoice = new Fl_Choice(50,10,150,25,"&myChoiceLabel");
	myChoice->user_data((void*)(this));	 // record self to be used by static callback functions
	Fl_Menu_Item ImpressionistUI::myChoiceMenu[3+1] = {
	  {"one",FL_ALT+'p', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)ONE},
	  {"two",FL_ALT+'l', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)TWO},
	  {"three",FL_ALT+'c', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)THREE},
	  {0}
	};
	myChoice->menu(myChoiceMenu);
	myChoice->callback(cb_myChoice);
	
	//-----The choice callback-------------------------
	void ImpressionistUI::cb_myChoice(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI *)(o->user_data()));
		ImpressionistDoc* pDoc=pUI->getDocument();

		int type=(int)v;

		pDoc->setMyType(type);
	}


//------------Button---------------------------------------

	//---To install a button---------------------------
	Fl_Button* myButton = new Fl_Button(330,220,50,20,"&myButtonLabel");
	myButton->user_data((void*)(this));   // record self to be used by static callback functions
	myButton->callback(cb_myButton);

	//---The button callback---------------------------
	void ImpressionistUI::cb_myButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI*)(o->user_data()));
		ImpressionistDoc* pDoc = pUI->getDocument();
		pDoc->startPainting();
	}


//---------Light Button------------------------------------
	
	//---To install a light button---------------------
	Fl_Light_Button* myLightButton = new Fl_Light_Button(240,10,150,25,"&myLightButtonLabel");
	myLightButton->user_data((void*)(this));   // record self to be used by static callback functions
	myLightButton->callback(cb_myLightButton);

	//---The light button callback---------------------
	void ImpressionistUI::cb_myLightButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI *pUI=((ImpressionistUI*)(o->user_data()));

		if (pUI->myBool==TRUE) pUI->myBool=FALSE;
		else pUI->myBool=TRUE;
	}

//----------Int Input--------------------------------------

    //---To install an int input-----------------------
	Fl_Int_Input* myInput = new Fl_Int_Input(200, 50, 5, 5, "&My Input");
	myInput->user_data((void*)(this));   // record self to be used by static callback functions
	myInput->callback(cb_myInput);

	//---The int input callback------------------------
	void ImpressionistUI::cb_myInput(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyInputValue=int( ((Fl_Int_Input *)o)->value() );
	}

//------------------------------------------------------------------------------------------------
*/

//------------------------------------- Help Functions --------------------------------------------

//------------------------------------------------------------
// This returns the UI, given the menu item.  It provides a
// link from the menu items to the UI
//------------------------------------------------------------
ImpressionistUI* ImpressionistUI::whoami(Fl_Menu_* o)	
{
	return ( (ImpressionistUI*)(o->parent()->user_data()) );
}


//--------------------------------- Callback Functions --------------------------------------------

//------------------------------------------------------------------
// Brings up a file chooser and then loads the chosen image
// This is called by the UI when the load image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_load_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
	if (newfile != NULL) {
		pDoc->loadImage(newfile);
	}
}


//------------------------------------------------------------------
// Brings up a file chooser and then saves the painted image
// This is called by the UI when the save image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_save_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Save File?", "*.bmp", "save.bmp" );
	if (newfile != NULL) {
		pDoc->saveImage(newfile);
	}
}

//-------------------------------------------------------------
// Brings up the paint dialog
// This is called by the UI when the brushes menu item
// is chosen
//-------------------------------------------------------------
void ImpressionistUI::cb_brushes(Fl_Menu_* o, void* v)
{
	whoami(o)->m_brushDialog->show();
}

//-------------------------------------------------------------
// Brings up the color selector
// This is called by the UI when the colors menu item
// is chosen
//-------------------------------------------------------------
void ImpressionistUI::cb_colors(Fl_Menu_* o, void* v)
{
	whoami(o)->m_colorSelector->show();
}

//-------------------------------------------------------------
// Brings up the paintly dialog
// This is called by the UI when the paintly menu item
// is chosen
//-------------------------------------------------------------
void ImpressionistUI::cb_paintly(Fl_Menu_* o, void* v)
{
	whoami(o)->m_paintlyDialog->show();
}

//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas(Fl_Menu_* o, void* v)
{
	ImpressionistDoc* pDoc=whoami(o)->getDocument();

	pDoc->clearCanvas();
}

//------------------------------------------------------------
// Causes the Impressionist program to exit
// Called by the UI when the quit menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_exit(Fl_Menu_* o, void* v) 
{
	whoami(o)->m_mainWindow->hide();
	whoami(o)->m_brushDialog->hide();
	whoami(o)->m_colorSelector->hide();
	whoami(o)->m_paintlyDialog->hide();

}



//-----------------------------------------------------------
// Brings up an about dialog box
// Called by the UI when the about menu item is chosen
//-----------------------------------------------------------
void ImpressionistUI::cb_about(Fl_Menu_* o, void* v) 
{
	fl_message("Impressionist FLTK version for CS341, Spring 2002");
}

//------- UI should keep track of the current for all the controls for answering the query from Doc ---------
//-------------------------------------------------------------
// Sets the type of brush to use to the one chosen in the brush 
// choice.  
// Called by the UI when a brush is chosen in the brush choice
//-------------------------------------------------------------
void ImpressionistUI::cb_brushChoice(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI = ((ImpressionistUI *)(o->user_data()));
	ImpressionistDoc* pDoc = pUI->getDocument();

	int type = (int)v;


	pDoc->setBrushType(type);
}

////-------------------------------------------------------------
//// Sets the type of brush to use to the one chosen in the  
//// stroke direction choice.  
//// Called by the UI when a brush is chosen in the stroke
//// direction choice
////-------------------------------------------------------------
//void ImpressionistUI::cb_brushStrokeDirectionChoice(Fl_Widget* o, void* v)
//{
//	ImpressionistUI* pUI = ((ImpressionistUI *)(o->user_data()));
//	ImpressionistDoc* pDoc = pUI->getDocument();
//
//	int type = (int)v;
//
//
//	pDoc->setStrokeDirection(type);
//}

//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas button is pushed
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas_button(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();

	pDoc->clearCanvas();
}


//-----------------------------------------------------------
// Updates the brush size to use from the value of the size
// slider
// Called by the UI when the size slider is moved
//-----------------------------------------------------------
void ImpressionistUI::cb_brushSizeSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushSize = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_brushLineWidthSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushLineWidth = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_brushLineAngleSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushLineAngle = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_brushAlphaSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushAlpha = float(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_brushEdgeClippingLightButton(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushEdgeClipping = !(((Fl_Light_Button *)o)->value());
}

void ImpressionistUI::cb_brushAnotherGradientLightButton(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushAnotherGradient = !(((Fl_Light_Button *)o)->value());
}

void ImpressionistUI::cb_brushSpacingSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushSpacing = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_brushRandomSizeLightButton(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushRandomSize = !(((Fl_Light_Button *)o)->value());
}

void ImpressionistUI::cb_brushPaintButton(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();
	// TODO
	pDoc->clearCanvas();
}

void ImpressionistUI::cb_brushEdgeThresholdSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nBrushEdgeThreshold = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyRunButton(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();
	// TODO
	pDoc->clearCanvas();
}

void ImpressionistUI::cb_paintlyThresholdSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyThreshold = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyCurvatureSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyCurvature = float(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyBlurSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyBlur = float(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyGridSizeSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyGridSize = float(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyMinStrokeLengthSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyMinStrokeLength = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyMaxStrokeLengthSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyMaxStrokeLength = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyAlphaSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyAlpha = float(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyLayerSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyLayer = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_paintlyR0LevelSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nPaintlyR0Level = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_brushDoItButton(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();
	// TODO
	pDoc->clearCanvas();
}

void ImpressionistUI::cb_load_edge_image(Fl_Menu_* o, void* v)
{
	ImpressionistDoc *pDoc = whoami(o)->getDocument();
	// TODO
	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName());
	if (newfile != NULL) {
		pDoc->loadImage(newfile);
	}
}

void ImpressionistUI::cb_load_another_image(Fl_Menu_* o, void* v)
{
	ImpressionistDoc *pDoc = whoami(o)->getDocument();
	// TODO
	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName());
	if (newfile != NULL) {
		pDoc->loadImage(newfile);
	}
}

//---------------------------------- per instance functions --------------------------------------

//------------------------------------------------
// Return the ImpressionistDoc used
//------------------------------------------------
ImpressionistDoc* ImpressionistUI::getDocument()
{
	return m_pDoc;
}

//------------------------------------------------
// Draw the main window
//------------------------------------------------
void ImpressionistUI::show() {
	m_mainWindow->show();
	m_paintView->show();
	m_origView->show();
}

//------------------------------------------------
// Change the paint and original window sizes to 
// w by h
//------------------------------------------------
void ImpressionistUI::resize_windows(int w, int h) {
	m_paintView->size(w,h);
	m_origView->size(w,h);
}

//------------------------------------------------ 
// Set the ImpressionistDoc used by the UI to 
// communicate with the brushes 
//------------------------------------------------
void ImpressionistUI::setDocument(ImpressionistDoc* doc)
{
	m_pDoc = doc;

	m_origView->m_pDoc = doc;
	m_paintView->m_pDoc = doc;
}

//------------------------------------------------
// Return the brush size
//------------------------------------------------
int ImpressionistUI::getBrushSize()
{
	return m_nBrushSize;
}

//-------------------------------------------------
// Set the brush size
//-------------------------------------------------
void ImpressionistUI::setBrushSize(int size)
{
	m_nBrushSize = size;

	if (size <= 40)
		m_BrushSizeSlider->value(m_nBrushSize);
}

int ImpressionistUI::getBrushLineWidth()
{
	return m_nBrushLineWidth;
}

void ImpressionistUI::setBrushLineWidth(int lineWidth)
{
	m_nBrushLineWidth = lineWidth;

	if (lineWidth <= 40)
		m_BrushLineWidthSlider->value(m_nBrushLineWidth);
}

int ImpressionistUI::getBrushLineAngle()
{
	return m_nBrushLineAngle;
}

void ImpressionistUI::setBrushLineAngle(int lineAngle)
{
	m_nBrushLineAngle = lineAngle;

	if (lineAngle <= 359)
		m_BrushLineAngleSlider->value(m_nBrushLineAngle);
}

float ImpressionistUI::getBrushAlpha()
{
	return m_nBrushAlpha;
}

void ImpressionistUI::setBrushAlpha(float alpha)
{
	m_nBrushAlpha = alpha;

	if (alpha <= 1.00)
		m_BrushAlphaSlider->value(m_nBrushAlpha);
}

bool ImpressionistUI::getBrushEdgeClipping()
{
	return m_nBrushEdgeClipping;
}

void ImpressionistUI::setBrushEdgeClipping(bool edgeClipping)
{
	m_nBrushEdgeClipping = edgeClipping;
}

bool ImpressionistUI::getBrushAnotherGradient()
{
	return m_nBrushAnotherGradient;
}

void ImpressionistUI::setBrushAnotherGradient(bool anotherGradient)
{
	m_nBrushAnotherGradient = anotherGradient;
}

int ImpressionistUI::getBrushSpacing()
{
	return m_nBrushSpacing;
}

void ImpressionistUI::setBrushSpacing(int spacing)
{
	m_nBrushSpacing = spacing;
}

bool ImpressionistUI::getBrushRandomSize()
{
	return m_nBrushRandomSize;
}

void ImpressionistUI::setBrushRandomSize(bool randomSize)
{
	m_nBrushRandomSize = randomSize;
}

int ImpressionistUI::getBrushEdgeThreshold()
{
	return m_nBrushEdgeThreshold;
}

void ImpressionistUI::setBrushEdgeThreshold(int edgeThreshold)
{
	m_nBrushEdgeThreshold = edgeThreshold;
}

int ImpressionistUI::getPaintlyThreshold()
{
	return m_nPaintlyThreshold;
}

void ImpressionistUI::setPaintlyThreshold(int threshold)
{
	m_nPaintlyThreshold = threshold;
}

float ImpressionistUI::getPaintlyCurvature()
{
	return m_nPaintlyCurvature;
}

void ImpressionistUI::setPaintlyCurvature(float curvature)
{
	m_nPaintlyCurvature = curvature;
}

float ImpressionistUI::getPaintlyBlur()
{
	return m_nPaintlyBlur;
}

void ImpressionistUI::setPaintlyBlur(float blur)
{
	m_nPaintlyBlur = blur;
}

float ImpressionistUI::getPaintlyGridSize()
{
	return m_nPaintlyGridSize;
}

void ImpressionistUI::setPaintlyGridSize(float gridSize)
{
	m_nPaintlyGridSize = gridSize;
}

int ImpressionistUI::getPaintlyMinStrokeLength()
{
	return m_nPaintlyMinStrokeLength;
}

void ImpressionistUI::setPaintlyMinStrokeLength(int minStrokeLength)
{
	m_nPaintlyMinStrokeLength = minStrokeLength;
}

int ImpressionistUI::getPaintlyMaxStrokeLength()
{
	return m_nPaintlyMaxStrokeLength;
}

void ImpressionistUI::setPaintlyMaxStrokeLength(int maxStrokeLength)
{
	m_nPaintlyMaxStrokeLength = maxStrokeLength;
}

float ImpressionistUI::getPaintlyAlpha()
{
	return m_nPaintlyAlpha;
}

void ImpressionistUI::setPaintlyAlpha(float alpha)
{
	m_nPaintlyAlpha = alpha;
}

int ImpressionistUI::getPaintlyLayer()
{
	return m_nPaintlyLayer;
}

void ImpressionistUI::setPaintlyLayer(int layer)
{
	m_nPaintlyLayer = layer;
}

int ImpressionistUI::getPaintlyR0Level()
{
	return m_nPaintlyR0Level;
}

void ImpressionistUI::setPaintlyR0Level(int r0Level)
{
	m_nPaintlyR0Level = r0Level;
}

// Main menu definition
Fl_Menu_Item ImpressionistUI::menuitems[] = {
	{ "&File",		0, 0, 0, FL_SUBMENU },
		{ "&Load Image...",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load_image },
		{ "&Save Image...",	FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save_image },
		{ "&Brushes...",	FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_brushes }, 
		{ "&Clear Canvas",	FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_clear_canvas, 0, FL_MENU_DIVIDER },
		{ "&Colors", FL_ALT + 'k', (Fl_Callback *)ImpressionistUI::cb_colors },
		{ "&Paintly", FL_ALT + 'p', (Fl_Callback *)ImpressionistUI::cb_paintly, 0, FL_MENU_DIVIDER },
		{ "Load Edge Image...", FL_ALT + 'e', (Fl_Callback *)ImpressionistUI::cb_load_edge_image },
		{ "Load Another Image...", FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_load_another_image, 0, FL_MENU_DIVIDER },
		{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
		{ 0 },

	{ "&Display", 0, 0, 0, FL_SUBMENU },
		{ "&Original Image", FL_ALT + 'o', (Fl_Callback *)ImpressionistUI::cb_about },
		{ "&Edge Image", FL_ALT + 'e', (Fl_Callback *)ImpressionistUI::cb_about },
		{ "&Another Image", FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
		{ 0 },

	{ "&Options", 0, 0, 0, FL_SUBMENU },
		{ "&Faster", FL_ALT + 'f', (Fl_Callback *)ImpressionistUI::cb_about },
		{ "&Safer", FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_about },
		{ 0 },

	{ "&Help",		0, 0, 0, FL_SUBMENU },
		{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
		{ 0 },

	{ 0 }
};

// Brush choice menu definition
Fl_Menu_Item ImpressionistUI::brushTypeMenu[NUM_BRUSH_TYPE + 1] = {
	{ "Points", FL_ALT + 'p', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_POINTS },
	{ "Lines", FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_LINES },
	{ "Circles", FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_CIRCLES },
	{ "Scattered Points", FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_POINTS },
	{ "Scattered Lines", FL_ALT + 'm', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_LINES },
	{ "Scattered Circles", FL_ALT + 'd', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_CIRCLES },
	{ 0 }
};

//// Stroke Direction choice menu definition
//Fl_Menu_Item ImpressionistUI::strokeDirectionMenu[NUM_STROKE_DIRECTION + 1] = {
//	{ "Slider/Right Mouse", FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_brushStrokeDirectionChoice, (void *)STROKE_SLIDER_RIGHT_MOUSE },
//	{ "Gradient", FL_ALT + 'g', (Fl_Callback *)ImpressionistUI::cb_brushStrokeDirectionChoice, (void *)STROKE_GRADIENT },
//	{ "Brush Direction", FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_brushStrokeDirectionChoice, (void *)STROKE_BRUSH_DIRECTION },
//	{ 0 }
//};



//----------------------------------------------------
// Constructor.  Creates all of the widgets.
// Add new widgets here
//----------------------------------------------------
ImpressionistUI::ImpressionistUI() {
	// Create the main window
	m_mainWindow = new Fl_Window(600, 300, "Impressionist");
		m_mainWindow->user_data((void*)(this));	// record self to be used by static callback functions
		// install menu bar
		m_menubar = new Fl_Menu_Bar(0, 0, 600, 25);
		m_menubar->menu(menuitems);

		// Create a group that will hold two sub windows inside the main
		// window
		Fl_Group* group = new Fl_Group(0, 25, 600, 275);

			// install paint view window
			m_paintView = new PaintView(300, 25, 300, 275, "This is the paint view");//0jon
			m_paintView->box(FL_DOWN_FRAME);

			// install original view window
			m_origView = new OriginalView(0, 25, 300, 275, "This is the orig view");//300jon
			m_origView->box(FL_DOWN_FRAME);
			m_origView->deactivate();

		group->end();
		Fl_Group::current()->resizable(group);
    m_mainWindow->end();

	// init values

	m_nBrushSize = 10;
	m_nBrushLineWidth = 1;
	m_nBrushLineAngle = 0;
	m_nBrushAlpha = 1.00;
	m_nBrushEdgeClipping = true;
	m_nBrushAnotherGradient = false;
	m_nBrushSpacing = 4;
	m_nBrushRandomSize = true;
	m_nBrushEdgeThreshold = 200;
	m_nPaintlyThreshold = 100;
	m_nPaintlyCurvature = 1.00;
	m_nPaintlyBlur = 0.50;
	m_nPaintlyGridSize = 1.00;
	m_nPaintlyMinStrokeLength = 4;
	m_nPaintlyMaxStrokeLength = 16;
	m_nPaintlyAlpha = 1.00;
	m_nPaintlyLayer = 3;
	m_nPaintlyR0Level = 3;
	
	// brush dialog definition
	m_brushDialog = new Fl_Window(400, 325, "Brush Dialog");
		// Add a brush type choice to the dialog
		m_BrushTypeChoice = new Fl_Choice(50,10,150,25,"&Brush");
		m_BrushTypeChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushTypeChoice->menu(brushTypeMenu);
		m_BrushTypeChoice->callback(cb_brushChoice);

		m_ClearCanvasButton = new Fl_Button(240,10,150,25,"&Clear Canvas");
		m_ClearCanvasButton->user_data((void*)(this));
		m_ClearCanvasButton->callback(cb_clear_canvas_button);

		//m_StrokeDirectionChoice = new Fl_Choice(10, 50, 150, 25, "&Stroke Direction");
		//m_StrokeDirectionChoice->user_data((void*)(this));	// record self to be used by static callback functions
		//m_StrokeDirectionChoice->menu(strokeDirectionMenu);
		//m_StrokeDirectionChoice->callback(cb_brushStrokeDirectionChoice);

		// Add brush size slider to the dialog 
		m_BrushSizeSlider = new Fl_Value_Slider(10, 80, 300, 20, "Size");
		m_BrushSizeSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushSizeSlider->type(FL_HOR_NICE_SLIDER);
		m_BrushSizeSlider->labelfont(FL_COURIER);
		m_BrushSizeSlider->labelsize(12);
		m_BrushSizeSlider->minimum(1);
		m_BrushSizeSlider->maximum(40);
		m_BrushSizeSlider->step(1);
		m_BrushSizeSlider->value(m_nBrushSize);
		m_BrushSizeSlider->align(FL_ALIGN_RIGHT);
		m_BrushSizeSlider->callback(cb_brushSizeSlides);

		m_BrushLineWidthSlider = new Fl_Value_Slider(10, 110, 300, 20, "Line Width");
		m_BrushLineWidthSlider->user_data((void*)(this));
		m_BrushLineWidthSlider->type(FL_HOR_NICE_SLIDER);
		m_BrushLineWidthSlider->labelfont(FL_COURIER);
		m_BrushLineWidthSlider->labelsize(12);
		m_BrushLineWidthSlider->minimum(1);
		m_BrushLineWidthSlider->maximum(40);
		m_BrushLineWidthSlider->step(1);
		m_BrushLineWidthSlider->value(m_nBrushLineWidth);
		m_BrushLineWidthSlider->align(FL_ALIGN_RIGHT);
		m_BrushLineWidthSlider->callback(cb_brushLineWidthSlides);

		m_BrushLineAngleSlider = new Fl_Value_Slider(10, 140, 300, 20, "Line Angle");
		m_BrushLineAngleSlider->user_data((void*)(this));
		m_BrushLineAngleSlider->type(FL_HOR_NICE_SLIDER);
		m_BrushLineAngleSlider->labelfont(FL_COURIER);
		m_BrushLineAngleSlider->labelsize(12);
		m_BrushLineAngleSlider->minimum(1);
		m_BrushLineAngleSlider->maximum(40);
		m_BrushLineAngleSlider->step(1);
		m_BrushLineAngleSlider->value(m_nBrushLineAngle);
		m_BrushLineAngleSlider->align(FL_ALIGN_RIGHT);
		m_BrushLineAngleSlider->callback(cb_brushLineAngleSlides);

		m_BrushAlphaSlider = new Fl_Value_Slider(10, 170, 300, 20, "Alpha");
		m_BrushAlphaSlider->user_data((void*)(this));
		m_BrushAlphaSlider->type(FL_HOR_NICE_SLIDER);
		m_BrushAlphaSlider->labelfont(FL_COURIER);
		m_BrushAlphaSlider->labelsize(12);
		m_BrushAlphaSlider->minimum(0.00);
		m_BrushAlphaSlider->maximum(1.00);
		m_BrushAlphaSlider->step(0.01);
		m_BrushAlphaSlider->value(m_nBrushAlpha);
		m_BrushAlphaSlider->align(FL_ALIGN_RIGHT);
		m_BrushAlphaSlider->callback(cb_brushAlphaSlides);

		m_BrushEdgeClippingLightButton = new Fl_Light_Button(10, 200, 150, 25, "&Edge Clipping");
		m_BrushEdgeClippingLightButton->user_data((void*)(this));
		m_BrushEdgeClippingLightButton->value(m_nBrushEdgeClipping);
		m_BrushEdgeClippingLightButton->callback(cb_brushEdgeClippingLightButton);

		m_BrushAnotherGradientLightButton = new Fl_Light_Button(240, 200, 150, 25, "&Another Gradient");
		m_BrushAnotherGradientLightButton->user_data((void*)(this));
		m_BrushAnotherGradientLightButton->value(m_nBrushAnotherGradient);
		m_BrushAnotherGradientLightButton->callback(cb_brushAnotherGradientLightButton);
		
		m_BrushPaintSpacingGroup = new Fl_Group(10, 230, 400, 30);

			m_BrushSpacingSlider = new Fl_Value_Slider(10, 230, 150, 20, "Spacing");
			m_BrushSpacingSlider->user_data((void*)(this));
			m_BrushSpacingSlider->type(FL_HOR_NICE_SLIDER);
			m_BrushSpacingSlider->labelfont(FL_COURIER);
			m_BrushSpacingSlider->labelsize(12);
			m_BrushSpacingSlider->minimum(1);
			m_BrushSpacingSlider->maximum(16);
			m_BrushSpacingSlider->step(1);
			m_BrushSpacingSlider->value(m_nBrushSpacing);
			m_BrushSpacingSlider->align(FL_ALIGN_RIGHT);
			m_BrushSpacingSlider->callback(cb_brushSpacingSlides);

			m_BrushRandomSizeLightButton = new Fl_Light_Button(230, 230, 100, 25, "&Size Rand.");
			m_BrushRandomSizeLightButton->user_data((void*)(this));
			m_BrushRandomSizeLightButton->value(m_nBrushRandomSize);
			m_BrushRandomSizeLightButton->callback(cb_brushRandomSizeLightButton);

			m_BrushPaintButton = new Fl_Button(340, 230, 50, 25, "&Paint");
			m_BrushPaintButton->user_data((void*)(this));
			m_BrushPaintButton->callback(cb_brushPaintButton);

		m_BrushPaintSpacingGroup->end();

		m_BrushEdgeThresholdGroup = new Fl_Group(10, 270, 400, 30);

			m_BrushEdgeThresholdSlider = new Fl_Value_Slider(10, 270, 220, 20, "Edge Threshold");
			m_BrushEdgeThresholdSlider->user_data((void*)(this));
			m_BrushEdgeThresholdSlider->type(FL_HOR_NICE_SLIDER);
			m_BrushEdgeThresholdSlider->labelfont(FL_COURIER);
			m_BrushEdgeThresholdSlider->labelsize(12);
			m_BrushEdgeThresholdSlider->minimum(0);
			m_BrushEdgeThresholdSlider->maximum(500);
			m_BrushEdgeThresholdSlider->step(1);
			m_BrushEdgeThresholdSlider->value(m_nBrushEdgeThreshold);
			m_BrushEdgeThresholdSlider->align(FL_ALIGN_RIGHT);
			m_BrushEdgeThresholdSlider->callback(cb_brushEdgeThresholdSlides);

			m_BrushDoItButton = new Fl_Button(340, 270, 50, 25, "&Do it");
			m_BrushDoItButton->user_data((void*)(this));
			m_BrushDoItButton->callback(cb_brushDoItButton);

		m_BrushEdgeThresholdGroup->end();

    m_brushDialog->end();	

	m_colorSelector = new Fl_Window(400, 325, "Color Selector");
	m_colorSelector->end();

	m_paintlyDialog = new Fl_Window(400, 325, "Paintly Dialog");

		//m_PaintlyStyleChoice = new Fl_Choice(50, 10, 100, 25, "&Style");
		//m_PaintlyStyleChoice->user_data((void*)(this));
		//m_PaintlyStyleChoice->menu(paintlyStyleMenu);
		//m_PaintlyStyleChoice->callback(cb_paintlyStyleChoice);

		//m_PaintlyStrokeChoice = new Fl_Choice(50, 120, 100, 25, "S&t&roke");
		//m_PaintlyStrokeChoice->user_data((void*)(this));
		//m_PaintlyStrokeChoice->menu(paintlyStrokeMenu);
		//m_PaintlyStrokeChoice->callback(cb_paintlyStrokeChoice);

		m_PaintlyRunButton = new Fl_Button(340, 10, 50, 25, "&Run");
		m_PaintlyRunButton->user_data((void*)(this));
		m_PaintlyRunButton->callback(cb_paintlyRunButton);

		m_PaintlyThresholdSlider = new Fl_Value_Slider(10, 50, 150, 20, "Threshold");
		m_PaintlyThresholdSlider->user_data((void*)(this));
		m_PaintlyThresholdSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyThresholdSlider->labelfont(FL_COURIER);
		m_PaintlyThresholdSlider->labelsize(12);
		m_PaintlyThresholdSlider->minimum(0);
		m_PaintlyThresholdSlider->maximum(250);
		m_PaintlyThresholdSlider->step(1);
		m_PaintlyThresholdSlider->value(m_nPaintlyThreshold);
		m_PaintlyThresholdSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyThresholdSlider->callback(cb_paintlyThresholdSlides);

		m_PaintlyCurvatureSlider = new Fl_Value_Slider(10, 80, 150, 20, "Curvature");
		m_PaintlyCurvatureSlider->user_data((void*)(this));
		m_PaintlyCurvatureSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyCurvatureSlider->labelfont(FL_COURIER);
		m_PaintlyCurvatureSlider->labelsize(12);
		m_PaintlyCurvatureSlider->minimum(0.00);
		m_PaintlyCurvatureSlider->maximum(1.00);
		m_PaintlyCurvatureSlider->step(0.01);
		m_PaintlyCurvatureSlider->value(m_nPaintlyCurvature);
		m_PaintlyCurvatureSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyCurvatureSlider->callback(cb_paintlyCurvatureSlides);

		m_PaintlyBlurSlider = new Fl_Value_Slider(10, 110, 150, 20, "Blur");
		m_PaintlyBlurSlider->user_data((void*)(this));
		m_PaintlyBlurSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyBlurSlider->labelfont(FL_COURIER);
		m_PaintlyBlurSlider->labelsize(12);
		m_PaintlyBlurSlider->minimum(0.00);
		m_PaintlyBlurSlider->maximum(1.00);
		m_PaintlyBlurSlider->step(0.01);
		m_PaintlyBlurSlider->value(m_nPaintlyBlur);
		m_PaintlyBlurSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyBlurSlider->callback(cb_paintlyBlurSlides);

		m_PaintlyGridSizeSlider = new Fl_Value_Slider(10, 140, 150, 20, "Grid Size");
		m_PaintlyGridSizeSlider->user_data((void*)(this));
		m_PaintlyGridSizeSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyGridSizeSlider->labelfont(FL_COURIER);
		m_PaintlyGridSizeSlider->labelsize(12);
		m_PaintlyGridSizeSlider->minimum(0.00);
		m_PaintlyGridSizeSlider->maximum(1.00);
		m_PaintlyGridSizeSlider->step(0.01);
		m_PaintlyGridSizeSlider->value(m_nPaintlyGridSize);
		m_PaintlyGridSizeSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyGridSizeSlider->callback(cb_paintlyGridSizeSlides);

		m_PaintlyMinStrokeLengthSlider = new Fl_Value_Slider(10, 170, 150, 20, "MinStrokeLength");
		m_PaintlyMinStrokeLengthSlider->user_data((void*)(this));
		m_PaintlyMinStrokeLengthSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyMinStrokeLengthSlider->labelfont(FL_COURIER);
		m_PaintlyMinStrokeLengthSlider->labelsize(12);
		m_PaintlyMinStrokeLengthSlider->minimum(0);
		m_PaintlyMinStrokeLengthSlider->maximum(30);
		m_PaintlyMinStrokeLengthSlider->step(1);
		m_PaintlyMinStrokeLengthSlider->value(m_nPaintlyMinStrokeLength);
		m_PaintlyMinStrokeLengthSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyMinStrokeLengthSlider->callback(cb_paintlyMinStrokeLengthSlides);

		m_PaintlyMaxStrokeLengthSlider = new Fl_Value_Slider(10, 200, 150, 20, "MaxStrokeLength");
		m_PaintlyMaxStrokeLengthSlider->user_data((void*)(this));
		m_PaintlyMaxStrokeLengthSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyMaxStrokeLengthSlider->labelfont(FL_COURIER);
		m_PaintlyMaxStrokeLengthSlider->labelsize(12);
		m_PaintlyMaxStrokeLengthSlider->minimum(0);
		m_PaintlyMaxStrokeLengthSlider->maximum(30);
		m_PaintlyMaxStrokeLengthSlider->step(1);
		m_PaintlyMaxStrokeLengthSlider->value(m_nPaintlyMaxStrokeLength);
		m_PaintlyMaxStrokeLengthSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyMaxStrokeLengthSlider->callback(cb_paintlyMaxStrokeLengthSlides);

		m_PaintlyAlphaSlider = new Fl_Value_Slider(10, 230, 150, 20, "Alpha");
		m_PaintlyAlphaSlider->user_data((void*)(this));
		m_PaintlyAlphaSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyAlphaSlider->labelfont(FL_COURIER);
		m_PaintlyAlphaSlider->labelsize(12);
		m_PaintlyAlphaSlider->minimum(0.00);
		m_PaintlyAlphaSlider->maximum(1.00);
		m_PaintlyAlphaSlider->step(0.01);
		m_PaintlyAlphaSlider->value(m_nPaintlyAlpha);
		m_PaintlyAlphaSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyAlphaSlider->callback(cb_paintlyAlphaSlides);

		m_PaintlyLayerSlider = new Fl_Value_Slider(10, 260, 150, 20, "Layers");
		m_PaintlyLayerSlider->user_data((void*)(this));
		m_PaintlyLayerSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyLayerSlider->labelfont(FL_COURIER);
		m_PaintlyLayerSlider->labelsize(12);
		m_PaintlyLayerSlider->minimum(0);
		m_PaintlyLayerSlider->maximum(30);
		m_PaintlyLayerSlider->step(1);
		m_PaintlyLayerSlider->value(m_nPaintlyLayer);
		m_PaintlyLayerSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyLayerSlider->callback(cb_paintlyLayerSlides);

		m_PaintlyR0LevelSlider = new Fl_Value_Slider(10, 290, 150, 20, "R0 Level");
		m_PaintlyR0LevelSlider->user_data((void*)(this));
		m_PaintlyR0LevelSlider->type(FL_HOR_NICE_SLIDER);
		m_PaintlyR0LevelSlider->labelfont(FL_COURIER);
		m_PaintlyR0LevelSlider->labelsize(12);
		m_PaintlyR0LevelSlider->minimum(0);
		m_PaintlyR0LevelSlider->maximum(30);
		m_PaintlyR0LevelSlider->step(1);
		m_PaintlyR0LevelSlider->value(m_nPaintlyR0Level);
		m_PaintlyR0LevelSlider->align(FL_ALIGN_RIGHT);
		m_PaintlyR0LevelSlider->callback(cb_paintlyR0LevelSlides);
		
		//TODO 6 sliders

	m_paintlyDialog->end();
}
