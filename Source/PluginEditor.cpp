#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SmeterAudioProcessorEditor::SmeterAudioProcessorEditor (SmeterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), meterIn(p.linkMeterInput())
{


    addAndMakeVisible(meterIn);
    

    
    setSize (1000, 500);
}

SmeterAudioProcessorEditor::~SmeterAudioProcessorEditor()
{
}

//==============================================================================
void SmeterAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));



    
}

void SmeterAudioProcessorEditor::resized()
{

    meterIn.Component::setBounds(50, 50, 60, 425);
    
}
