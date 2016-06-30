#include <common.hpp>

// TODO this could be done using macros (at all places is used ifdef)
bool debug_show_img_d1 = false;
bool debug_show_img_main = true;
bool debug_show_img_gray = false;
bool debug_show_img_face = false;
bool debug_show_img_optfl_eyes = false;
bool debug_show_img_templ_eyes_cor = true;
bool debug_show_img_templ_eyes_tmpl = true;
bool debug_show_img_farne_eyes = true;
bool debug_t1_log = false;
bool debug_t2_log = false;
bool debug_t2_perf_method = false;
bool debug_t2_perf_whole = false;
bool debug_t2_perf = false;
bool debug_tmpl_log = false;
bool debug_tmpl_perf1 = false;
bool debug_tmpl_perf2 = false;
bool debug_fb_log1 = false;
bool debug_fb_log_flow = true;
bool debug_fb_log_reinit = true;
bool debug_fb_log_repupil = true;
bool debug_fb_log_repupil1 = true;
bool debug_fb_perf1 = false;
bool debug_fb_perf2 = false;
bool debug_bp_log_pix = true;
bool debug_notifications_log1 = true;
bool debug_blinks_d1 = true;
bool debug_blinks_d2 = false;
bool debug_blinks_d3 = true;
bool debug_blinks_d4 = true;

//int method = METHOD_OPTFLOW;
//int method = METHOD_TEMPLATE_BASED;
int method = METHOD_FARNEBACK;
//int method = METHOD_BLACKPIXELS;
double previousFrameTime = -1;

// optical flow
int flg=0;

int farne = 0;

int leftXOffset=200, leftYOffset=130, leftCols=100, leftRows=100;
int rightXOffset=350, rightYOffset=130, rightCols=100, rightRows=100;

int leftXp1=0, leftYp1=0, rightXp1=0, rightYp1=0;
int leftXlast=0, leftYlast=0, rightXlast=0, rightYlast=0;
int leftXavg=0, leftYavg=0, rightXavg=0, rightYavg=0;
int eye_region_width, eye_region_height;
cv::TermCriteria termcrit;
cv::Size subPixWinSize, winSize;
const int MAX_COUNT = 500;
bool addRemovePtx = false;
cv::vector<cv::Point2f> points[2];
cv::Mat pleft, pright;
int firstLoopProcs = 1;

///