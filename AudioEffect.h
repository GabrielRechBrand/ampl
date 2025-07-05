#pragma once
#include <JuceHeader.h>

class AudioEffect
{
public:
    virtual ~AudioEffect() = default;

    // Prepara o efeito para tocar (configura sample rate, etc.)
    virtual void prepareToPlay(double sampleRate, int samplesPerBlock) = 0;

    // O coração do efeito, onde o áudio é processado
    virtual void process(juce::AudioBuffer<float>& buffer) = 0;

    // Zera o estado do efeito
    virtual void reset() = 0;
};
