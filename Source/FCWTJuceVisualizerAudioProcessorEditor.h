/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

// Forward declaration of FCWTJuceVisualizerAudioProcessor
class FCWTJuceVisualizerAudioProcessor;

#include "FCWTJuceVisualizerAudioProcessor.h"

//==============================================================================
/**
*/
class FCWTJuceVisualizerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FCWTJuceVisualizerAudioProcessorEditor (FCWTJuceVisualizerAudioProcessor& p);

    ~FCWTJuceVisualizerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FCWTJuceVisualizerAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FCWTJuceVisualizerAudioProcessorEditor)
};
