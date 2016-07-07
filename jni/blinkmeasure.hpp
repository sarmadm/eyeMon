
#ifndef BLINKMEASURE_H
#define BLINKMEASURE_H


class BlinkMeasure {
    public:
        unsigned int frameNum;
        double timestamp;
        double lcor;
        double rcor;
        bool canProceedL, canProceedR, canUpdateL, canUpdateR;
        // converting to chuncks
        static bool lAdding;
        static bool isFirst;
        static double prevLcor;
        static double prevRcor;
        static double lFirstBlinkT;
        static double lLastNonBlinkT;
        static unsigned int lFirstBlinkF;
        static unsigned int lLastNonBlinkF;
        static bool rAdding;
        static double rFirstBlinkT;
        static double rLastNonBlinkT;
        static unsigned int rFirstBlinkF;
        static unsigned int rLastNonBlinkF;
        static unsigned int lLastAddedFN;
        static unsigned int rLastAddedFN;
        static double maxNonBlinkT;

        BlinkMeasure();
        BlinkMeasure(unsigned int frameNum, double timestamp, double lcor, double rcor);
        static void measureBlinks();
        static bool joinBlinks();
        static void measureBlinksAVG(int shortBmSize, double *lavg, double *ravg);
        static void measureBlinksSD(double *lSD, double *rSD, double *lsdt, double *rsdt, double *plsdf, double *prsdf, double *mlsdf, double *mrsdf);
        static void makeChunk(bool isLeft, double timestamp, bool isBlink, unsigned int frameNum);
        static void makeNotification(bool isLeft);
};

class Blink {
    public:
        unsigned int frameStart;
        unsigned int frameEnd;
        double timestampStart;
        double timestampEnd;
        int eventType;
        //double corAvg;
        Blink(unsigned int frameStart, unsigned int frameEnd, double timestampStart, double timestampEnd, int eventType);
};

#endif
