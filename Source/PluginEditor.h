#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "VerticalMeter.h"

//==============================================================================

class SmeterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SmeterAudioProcessorEditor (SmeterAudioProcessor&);
    ~SmeterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
  
    SmeterAudioProcessor& audioProcessor;
    
    VerticalMeter meterIn;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SmeterAudioProcessorEditor)
};
