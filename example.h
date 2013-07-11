#ifndef __MC_EXEC_PRINTING__
#define __MC_EXEC_PRINTING__

#ifndef __MC_SYSDEFS__
#include "sysdefs.h"
#endif

typedef intset_t MCPrintingPrinterFeatures;
enum /* MCPrintingPrinterFeatures */
{
	kMCPrintingPrinterFeaturesCollate,
	kMCPrintingPrinterFeaturesCopies,
	kMCPrintingPrinterFeaturesColor,
	kMCPrintingPrinterFeaturesDuplex,
};

enum MCPrintingPrinterPageOrientation
{
	kMCPrintingPrinterPageOrientationPortrait,
	kMCPrintingPrinterPageOrientationReversePortrait,
	kMCPrintingPrinterPageOrientationLandscape,
	kMCPrintingPrinterPageOrientationReverseLandscape,
};

enum MCPrintingPrinterJobDuplex
{
	kMCPrintingPrinterJobDuplexNone,
	kMCPrintingPrinterJobDuplexShortEdge,
	kMCPrintingPrinterJobDuplexLongEdge,
};

//////////

enum MCPrintingPrinterPageRangeRepType
{
	kMCPrintingPrinterPageRangeRepTypeAll,
	kMCPrintingPrinterPageRangeRepTypeCurrent,
	kMCPrintingPrinterPageRangeRepTypeSelection,
	kMCPrintingPrinterPageRangeRepTypeCustom,
};

struct MCPrintingPrinterPageRangeRep
{
	MCPrintingPrinterPageRangeRepType type;
	union
	{
		MCStringRef custom;
	};
};

struct MCPrintingPrinterPageRange;

void MCPrintingPrinterPageRangeFree(MCExecContext& ctxt, MCPrintingPrinterPageRange& value);
void MCPrintingPrinterPageRangeCopy(MCExecContext& ctxt, MCPrintingPrinterPageRange& src_value, MCPrintingPrinterPageRange& dst_value);
//void MCPrintingPrinterPageRangeEncode(MCExecContext& ctxt, MCPrintingPrinterPageRangeRep& rep, MCPrintingPrinterPageRange& value, MCExecErrorInfo*& r_error);
void MCPrintingPrinterPageRangeDecode(MCExecContext& ctxt, MCPrintingPrinterPageRange& value, MCPrintingPrinterPageRangeRep& rep);

//////////

enum MCPrintingPrinterDeviceOutputRepType
{
	kMCPrintingPrinterDeviceOutputRepTypeDevice,
	kMCPrintingPrinterDeviceOutputRepTypePreview,
	kMCPrintingPrinterDeviceOutputRepTypeSystem,
	kMCPrintingPrinterDeviceOutputRepTypeCustom,
};

struct MCPrintingPrinterDeviceOutputRep
{
	MCPrintingPrinterDeviceOutputRepType type;
	union
	{
		MCStringRef custom;
	};
};

struct MCPrintingPrinterDeviceOutput;

void MCPrintingPrinterDeviceOutputFree(MCExecContext& ctxt, MCPrintingPrinterDeviceOutput& value);
void MCPrintingPrinterDeviceOutputCopy(MCExecContext& ctxt, const MCPrintingPrinterDeviceOutput& src_value, MCPrintingPrinterDeviceOutput& dst_value);
//void MCPrintingPrinterDeviceOutputEncode(MCExecContext& ctxt, MCPrintingPrinterDeviceOutputRep& rep, MCPrintingPrinterDeviceOutput& value, MCExecErrorInfo*& r_error);
void MCPrintingPrinterDeviceOutputDecode(MCExecContext& ctxt, const MCPrintingPrinterDeviceOutput& value, MCPrintingPrinterDeviceOutputRep& rep);

//////////

void MCPrintingExecAnswerPageSetup(MCExecContext &ctxt, bool p_is_sheet);
void MCPrintingExecAnswerPrinter(MCExecContext &ctxt, bool p_is_sheet);

void MCPrintingExecCancelPrinting(MCExecContext& ctxt);
void MCPrintingExecResetPrinting(MCExecContext& ctxt);
void MCPrintingExecPrintAnchor(MCExecContext& ctxt, MCStringRef name, MCPoint location);
void MCPrintingExecPrintLink(MCExecContext& ctxt, int type, MCStringRef target, MCRectangle area);
void MCPrintingExecPrintNativeBookmark(MCExecContext& ctxt, MCStringRef title, MCPoint location, integer_t level, bool initially_closed);
void MCPrintingExecPrintUnicodeBookmark(MCExecContext& ctxt, MCStringRef title, MCPoint location, integer_t level, bool initially_closed);
void MCPrintingExecPrintBreak(MCExecContext& ctxt);
void MCPrintingExecPrintAllCards(MCExecContext& ctxt, MCStack *stack, bool only_marked);
void MCPrintingExecPrintRectOfAllCards(MCExecContext& ctxt, MCStack *stack, bool p_only_marked, MCPoint from, MCPoint to);
void MCPrintingExecPrintCard(MCExecContext& ctxt, MCCard *target);
void MCPrintingExecPrintRectOfCard(MCExecContext& ctxt, MCCard *target, MCPoint from, MCPoint to);
void MCPrintingExecPrintSomeCards(MCExecContext& ctxt, integer_t count);
void MCPrintingExecPrintRectOfSomeCards(MCExecContext& ctxt, integer_t count, MCPoint from, MCPoint to);
void MCPrintingExecPrintCardIntoRect(MCExecContext& ctxt, MCCard *card, MCRectangle destination);
void MCPrintingExecPrintRectOfCardIntoRect(MCExecContext& ctxt, MCCard *card, MCPoint from, MCPoint to, MCRectangle destination);

void MCPrintingExecClosePrinting(MCExecContext& ctxt);

void MCPrintingExecOpenPrintingToDestination(MCExecContext& ctxt, MCStringRef p_destination, MCStringRef p_filename, MCArrayRef p_options);
void MCPrintingExecOpenPrinting(MCExecContext& ctxt);
void MCPrintingExecOpenPrintingWithDialog(MCExecContext& ctxt, bool p_as_sheet);

void MCPrintingGetPrinterNames(MCExecContext& ctxt, MCStringRef& r_printers);

void MCPrintingGetPrintDeviceFeatures(MCExecContext& ctxt, MCPrintingPrinterFeatures& r_features);
void MCPrintingSetPrintDeviceOutput(MCExecContext& ctxt, const MCPrintingPrinterDeviceOutput& output);
void MCPrintingGetPrintDeviceOutput(MCExecContext& ctxt, MCPrintingPrinterDeviceOutput& r_output);
void MCPrintingGetPrintDeviceRectangle(MCExecContext& ctxt, MCRectangle &r_rectangle);
void MCPrintingGetPrintDeviceRectangle(MCExecContext& ctxt, MCRectangle &r_rectangle);
void MCPrintingGetPrintDeviceSettings(MCExecContext& ctxt, MCStringRef &r_settings);
void MCPrintingSetPrintDeviceSettings(MCExecContext& ctxt, MCStringRef p_settings);
void MCPrintingGetPrintDeviceName(MCExecContext& ctxt, MCStringRef &r_name);
void MCPrintingSetPrintDeviceName(MCExecContext& ctxt, MCStringRef p_name);

void MCPrintingGetPrintPageOrientation(MCExecContext& ctxt, MCPrintingPrinterPageOrientation& r_orientation);
void MCPrintingSetPrintPageOrientation(MCExecContext& ctxt, MCPrintingPrinterPageOrientation orientation);

void MCPrintingSetPrintJobRanges(MCExecContext& ctxt, const MCPrintingPrinterPageRange& p_ranges);
void MCPrintingGetPrintJobRanges(MCExecContext& ctxt, MCPrintingPrinterPageRange& r_ranges);

void MCPrintingSetPrintPageSize(MCExecContext& ctxt, integer_t p_value[2]);
void MCPrintingGetPrintPageSize(MCExecContext& ctxt, integer_t r_value[2]);
void MCPrintingSetPrintPageScale(MCExecContext& ctxt, double p_value);
void MCPrintingGetPrintPageScale(MCExecContext& ctxt, double &r_value);
void MCPrintingGetPrintPageRectangle(MCExecContext& ctxt, MCRectangle &r_value);

void MCPrintingGetPrintJobName(MCExecContext& ctxt, MCStringRef &r_value);
void MCPrintingSetPrintJobName(MCExecContext& ctxt, MCStringRef p_value);
void MCPrintingGetPrintJobCopies(MCExecContext& ctxt, integer_t &r_value);
void MCPrintingSetPrintJobCopies(MCExecContext& ctxt, integer_t p_value);
void MCPrintingGetPrintJobDuplex(MCExecContext& ctxt, MCPrintingPrinterJobDuplex& r_value);
void MCPrintingSetPrintJobDuplex(MCExecContext& ctxt, MCPrintingPrinterJobDuplex p_value);
void MCPrintingGetPrintJobCollate(MCExecContext& ctxt, bool &r_value);
void MCPrintingSetPrintJobCollate(MCExecContext& ctxt, bool p_value);
void MCPrintingGetPrintJobColor(MCExecContext& ctxt, bool &r_value);
void MCPrintingSetPrintJobColor(MCExecContext& ctxt, bool p_value);
void MCPrintingGetPrintJobPage(MCExecContext& ctxt, integer_t &r_value);

void MCPrintingGetPrintCardBorders(MCExecContext& ctxt, bool &r_card_borders);
void MCPrintingSetPrintCardBorders(MCExecContext& ctxt, bool p_card_borders);
void MCPrintingGetPrintGutters(MCExecContext& ctxt, integer_t r_gutters[2]);
void MCPrintingSetPrintGutters(MCExecContext& ctxt, integer_t p_gutters[2]);
void MCPrintingGetPrintMargins(MCExecContext& ctxt, integer_t r_margins[4]);
void MCPrintingSetPrintMargins(MCExecContext& ctxt, integer_t p_margins[4]);
void MCPrintingGetPrintRowsFirst(MCExecContext& ctxt, bool &r_rows_first);
void MCPrintingSetPrintRowsFirst(MCExecContext& ctxt, bool p_rows_first);
void MCPrintingGetPrintScale(MCExecContext& ctxt, double &r_scale);
void MCPrintingSetPrintScale(MCExecContext& ctxt, double p_scale);
void MCPrintingGetPrintRotated(MCExecContext& ctxt, bool &r_rotated);
void MCPrintingSetPrintRotated(MCExecContext& ctxt, bool p_rotated);
void MCPrintingGetPrintCommand(MCExecContext& ctxt, MCStringRef &r_command);
void MCPrintingSetPrintCommand(MCExecContext& ctxt, MCStringRef p_command);
void MCPrintingGetPrintFontTable(MCExecContext& ctxt, MCStringRef &r_table);
void MCPrintingSetPrintFontTable(MCExecContext& ctxt, MCStringRef p_table);

#endif
