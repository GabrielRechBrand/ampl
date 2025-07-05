// GainPedal.h
#pragma once
#include "AudioEffect.h"

class GainPedal : public AudioEffect
{
public:
    GainPedal(juce::AudioProcessorValueTreeState& apvts);
    ~GainPedal() override = default;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void process(juce::AudioBuffer<float>& buffer) override;
    void reset() override;

private:
    juce::AudioProcessorValueTreeState& apvts;
    std::atomic<float>* gainParameter = nullptr;
};
