// WaveletTransform.h
#include <vector>
#include <complex>
#include "fcwt.h"

class WaveletTransform {
public:
    WaveletTransform(int sampleRate);
    ~WaveletTransform();

    void setParameters(float f0, float f1, int fn);
    void process(const std::vector<float>& input, std::vector<std::complex<float>>& output);

private:
    FCWT fcwt;
    Scales* scales;
    int sampleRate;
    float f0, f1;
    int fn;
};
