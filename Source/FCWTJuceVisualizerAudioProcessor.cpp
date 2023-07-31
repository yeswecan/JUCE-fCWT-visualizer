// FCWTJuceVisualizerAudioProcessor.cpp
#include "FCWTJuceVisualizerAudioProcessor.h"

FCWTJuceVisualizerAudioProcessor::FCWTJuceVisualizerAudioProcessor() : historySize(20 * 44100) { // 20 seconds at 44100 Hz
    // Initialize parameters here
}

FCWTJuceVisualizerAudioProcessor::~FCWTJuceVisualizerAudioProcessor() {
    delete waveletTransform;
}

void FCWTJuceVisualizerAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    if (waveletTransform != nullptr) {
        delete waveletTransform;
    }
    waveletTransform = new WaveletTransform(sampleRate, 0.1f, 20.0f, 200);
}

void FCWTJuceVisualizerAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    int numSamples = buffer.getNumSamples();
    std::vector<float> input(numSamples);
    std::vector<std::complex<float>> cwtResult(numSamples * 200);
    for (int i = 0; i < numSamples; ++i) {
        input[i] = buffer.getSample(0, i);
    }
    waveletTransform->process(input, cwtResult);
    cwtHistory.push_back(cwtResult);
    while (cwtHistory.size() > historySize) {
        cwtHistory.pop_front();
    }
}

void FCWTJuceVisualizerAudioProcessor::setParameters(float f0, float f1, int fn) {
    waveletTransform->setParameters(f0, f1, fn);
    cwtHistory.clear(); // Clear history when parameters change
}

const std::deque<std::vector<std::complex<float>>>& FCWTJuceVisualizerAudioProcessor::getCwtHistory() const {
    return cwtHistory;
}


//==============================================================================
bool FCWTJuceVisualizerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* FCWTJuceVisualizerAudioProcessor::createEditor()
{
    return new FCWTJuceVisualizerAudioProcessorEditor (*this);
}

//==============================================================================
void FCWTJuceVisualizerAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FCWTJuceVisualizerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FCWTJuceVisualizerAudioProcessor();
}

void FCWTJuceVisualizerAudioProcessor::releaseResources() {
    return;
}

const juce::String FCWTJuceVisualizerAudioProcessor::getName() const {
    return "FCWT JUCE Visualizer";
}

double FCWTJuceVisualizerAudioProcessor::getTailLengthSeconds() const {
    return 0.0;
}

int FCWTJuceVisualizerAudioProcessor::getNumPrograms() {
    return 1;
}

int FCWTJuceVisualizerAudioProcessor::getCurrentProgram() {
    return 0;
}

void FCWTJuceVisualizerAudioProcessor::setCurrentProgram (int index) {
    // This is a placeholder
}

const juce::String FCWTJuceVisualizerAudioProcessor::getProgramName (int index) {
    return {};
}

void FCWTJuceVisualizerAudioProcessor::changeProgramName (int index, const juce::String& newName) {
    // This is a placeholder
}

bool FCWTJuceVisualizerAudioProcessor::acceptsMidi() const {
    return false;
}

bool FCWTJuceVisualizerAudioProcessor::producesMidi() const {
    return false;
}

bool FCWTJuceVisualizerAudioProcessor::isMidiEffect() const {
    return false;
}
