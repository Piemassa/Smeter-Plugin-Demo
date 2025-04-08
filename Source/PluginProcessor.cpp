#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SmeterAudioProcessor::SmeterAudioProcessor()

{
}

SmeterAudioProcessor::~SmeterAudioProcessor()
{
}

//==============================================================================
void SmeterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    meterInput.prepareToPlay(sampleRate);
}

void SmeterAudioProcessor::releaseResources()
{

}

void SmeterAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto inCh  = getTotalNumInputChannels();
    auto outCh = getTotalNumOutputChannels();
    const int numSamples = buffer.getNumSamples();

    for (auto i = inCh; i < outCh; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    meterInput.processBlock(buffer, numSamples, inCh, outCh);
    

}

//==============================================================================

juce::AudioProcessorEditor* SmeterAudioProcessor::createEditor()
{
    return new SmeterAudioProcessorEditor (*this);
}

//==============================================================================
void SmeterAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
//    auto state = parameters.copyState();
//    std::unique_ptr<XmlElement> xml (state.createXml());
//    copyXmlToBinary(*xml, destData);
}

void SmeterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
//    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data,sizeInBytes));
//    if (xmlState.get() != nullptr)
//    {
//        if (xmlState -> hasTagName(parameters.state.getType()))
//        {
//            parameters.replaceState(ValueTree::fromXml(*xmlState));
//        }
//    }
}

//==============================================================================
// This creates new instances of the plugin..



MeterPersonale::MeteringDsp& SmeterAudioProcessor::linkMeterInput()
{
    return meterInput;
}





juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SmeterAudioProcessor();
}
