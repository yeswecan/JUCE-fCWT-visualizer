// WaveletTransform.cpp
#include "WaveletTransform.h"

WaveletTransform::WaveletTransform(int sampleRate, float f0, float f1, int fn)
    : sampleRate(sampleRate), f0(f0), f1(f1), fn(fn), morlet(1.0f), fcwt(&morlet, 8, true, false) {
    scales = new Scales(&morlet, FCWT_LINFREQS, sampleRate, f0, f1, fn);
}

WaveletTransform::~WaveletTransform() {
    delete scales;
}

void WaveletTransform::setParameters(float f0, float f1, int fn) {
    this->f0 = f0;
    this->f1 = f1;
    this->fn = fn;
    delete scales;
    scales = new Scales(&morlet, FCWT_LINFREQS, sampleRate, f0, f1, fn);
}

void WaveletTransform::process(const std::vector<float>& input, std::vector<std::complex<float>>& output) {
    std::vector<std::complex<float>> inputComplex(input.size());
    for (int i = 0; i < input.size(); ++i) {
        inputComplex[i] = std::complex<float>(input[i], 0.0f);
    }
    fcwt.cwt(&inputComplex[0], input.size(), &output[0], scales);
}
