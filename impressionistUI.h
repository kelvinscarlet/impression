//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_file_chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>

#include "Impressionist.h"
#include "OriginalView.h"
#include "PaintView.h"

#include "ImpBrush.h"

class ImpressionistUI {
public:
	ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

	// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;
	//Fl_Choice*			m_StrokeDirectionChoice;

	Fl_Slider*			m_BrushSizeSlider;
	Fl_Slider*			m_BrushLineWidthSlider;
	Fl_Slider*			m_BrushLineAngleSlider;
	Fl_Slider*			m_BrushAlphaSlider;

	Fl_Light_Button*	m_BrushEdgeClippingLightButton;
	Fl_Light_Button*	m_BrushAnotherGradientLightButton;

	Fl_Group*			m_BrushPaintSpacingGroup;
	Fl_Value_Slider*	m_BrushSpacingSlider;
	Fl_Light_Button*	m_BrushRandomSizeLightButton;
	Fl_Button*			m_BrushPaintButton;

	Fl_Group*			m_BrushEdgeThresholdGroup;
	Fl_Value_Slider*	m_BrushEdgeThresholdSlider;
	Fl_Button*			m_BrushDoItButton;
	
	Fl_Button*          m_ClearCanvasButton;

	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getBrushSize();
	void				setBrushSize(int size);

	int					getBrushLineWidth();
	void				setBrushLineWidth(int lineWidth);

	int					getBrushLineAngle();
	void				setBrushLineAngle(int lineAngle);

	float				getBrushAlpha();
	void				setBrushAlpha(float alpha);

	bool				getBrushEdgeClipping();
	void				setBrushEdgeClipping(bool edgeClipping);

	bool				getBrushAnotherGradient();
	void				setBrushAnotherGradient(bool anotherGradient);

	int					getBrushSpacing();
	void				setBrushSpacing(int spacing);

	bool				getBrushRandomSize();
	void				setBrushRandomSize(bool randomSize);

	int					getBrushEdgeThreshold();
	void				setBrushEdgeThreshold(int edgeThreshold);

	// for color selector
	Fl_Window*			m_colorSelector;

	// for color selector
	Fl_Window*			m_paintlyDialog;

	Fl_Button*			m_PaintlyRunButton;

	Fl_Slider*			m_PaintlyThresholdSlider;
	Fl_Slider*			m_PaintlyCurvatureSlider;
	Fl_Slider*			m_PaintlyBlurSlider;
	Fl_Slider*			m_PaintlyGridSizeSlider;
	Fl_Slider*			m_PaintlyMinStrokeLengthSlider;
	Fl_Slider*			m_PaintlyMaxStrokeLengthSlider;
	Fl_Slider*			m_PaintlyAlphaSlider;
	Fl_Slider*			m_PaintlyLayerSlider;
	Fl_Slider*			m_PaintlyR0LevelSlider;

	int					getPaintlyThreshold();
	void				setPaintlyThreshold(int threshold);

	float				getPaintlyCurvature();
	void				setPaintlyCurvature(float curvature);

	float				getPaintlyBlur();
	void				setPaintlyBlur(float blur);

	float				getPaintlyGridSize();
	void				setPaintlyGridSize(float gridSize);

	int					getPaintlyMinStrokeLength();
	void				setPaintlyMinStrokeLength(int minStrokeLength);

	int					getPaintlyMaxStrokeLength();
	void				setPaintlyMaxStrokeLength(int maxStrokeLength);

	float				getPaintlyAlpha();
	void				setPaintlyAlpha(float alpha);

	int					getPaintlyLayer();
	void				setPaintlyLayer(int layer);

	int					getPaintlyR0Level();
	void				setPaintlyR0Level(int r0Level);

private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int		m_nBrushSize;
	int		m_nBrushLineWidth;
	int		m_nBrushLineAngle;
	float	m_nBrushAlpha;
	bool	m_nBrushEdgeClipping;
	bool	m_nBrushAnotherGradient;
	int		m_nBrushSpacing;
	bool	m_nBrushRandomSize;
	int		m_nBrushEdgeThreshold;
	int		m_nPaintlyThreshold;
	float	m_nPaintlyCurvature;
	float	m_nPaintlyBlur;
	float	m_nPaintlyGridSize;
	int		m_nPaintlyMinStrokeLength;
	int		m_nPaintlyMaxStrokeLength;
	float	m_nPaintlyAlpha;
	int		m_nPaintlyLayer;
	int		m_nPaintlyR0Level;

	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE + 1];
	//static Fl_Menu_Item		strokeDirectionMenu[NUM_STROKE_DIRECTION + 1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_colors(Fl_Menu_* o, void* v);
	static void	cb_paintly(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	//static void	cb_brushStrokeDirectionChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_brushSizeSlides(Fl_Widget* o, void* v);
	static void	cb_brushLineWidthSlides(Fl_Widget* o, void* v);
	static void	cb_brushLineAngleSlides(Fl_Widget* o, void* v);
	static void	cb_brushAlphaSlides(Fl_Widget* o, void* v);
	static void	cb_brushEdgeClippingLightButton(Fl_Widget* o, void* v);
	static void	cb_brushAnotherGradientLightButton(Fl_Widget* o, void* v);
	static void	cb_brushSpacingSlides(Fl_Widget* o, void* v);
	static void	cb_brushRandomSizeLightButton(Fl_Widget* o, void* v);
	static void	cb_brushPaintButton(Fl_Widget* o, void* v);
	static void	cb_brushEdgeThresholdSlides(Fl_Widget* o, void* v);
	static void	cb_brushDoItButton(Fl_Widget* o, void* v);
	static void	cb_paintlyRunButton(Fl_Widget* o, void* v);
	static void	cb_paintlyThresholdSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyCurvatureSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyBlurSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyGridSizeSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyMinStrokeLengthSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyMaxStrokeLengthSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyAlphaSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyLayerSlides(Fl_Widget* o, void* v);
	static void	cb_paintlyR0LevelSlides(Fl_Widget* o, void* v);
	static void	cb_load_edge_image(Fl_Menu_* o, void* v);
	static void	cb_load_another_image(Fl_Menu_* o, void* v);

};

#endif
