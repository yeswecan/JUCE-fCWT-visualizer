// FCWTJuceVisualizerAudioProcessor.h

#pragma once

#include "WaveletTransform.h"
#include <deque>
#include <JuceHeader.h>
#include "FCWTJuceVisualizerAudioProcessorEditor.h"

//using namespace juce;

class FCWTJuceVisualizerAudioProcessor : public juce::AudioProcessor {
public:
    FCWTJuceVisualizerAudioProcessor();
    ~FCWTJuceVisualizerAudioProcessor();

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override;

    void setParameters(float f0, float f1, int fn);
    const std::deque<std::vector<std::complex<float>>>& getCwtHistory() const;
    
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    // ...
    const juce::String getName() const override;
    double getTailLengthSeconds() const override;
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    void releaseResources() override;
    // ...
    

private:
    WaveletTransform* waveletTransform;
    std::deque<std::vector<std::complex<float>>> cwtHistory;
    int historySize;
    
    
};

