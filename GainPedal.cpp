// GainPedal.cpp
#include "GainPedal.h"
#include "../../Source/PluginProcessor.h"

GainPedal::GainPedal(juce::AudioProcessorValueTreeState& apvts) : apvts(apvts) {}

void GainPedal::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Pegamos um ponteiro para o valor do nosso parâmetro "GAIN"
    gainParameter = apvts.getRawParameterValue("GAIN");
}

void GainPedal::process(juce::AudioBuffer<float>& buffer)
{
    // Pegamos o valor atual do knob de ganho
    const float gainValue = gainParameter->load();

    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = std::tanh(channelData[sample] * gainValue);
        }
    }
}

void GainPedal::reset() {}