#pragma once
/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "Gui/Knob.h"
#include "Gui/TooglableButton.h"
#include "Gui/ButtonList.h"


//==============================================================================
/**
*/
class ObxdAudioProcessorEditor  :
	public AudioProcessorEditor,
                          public ChangeListener,
						  public Slider::Listener,
						  public Button::Listener,
						  public ComboBox::Listener//,
						 // public AudioProcessorListener

{
public:
    ObxdAudioProcessorEditor (ObxdAudioProcessor* ownerFilter);
    ~ObxdAudioProcessorEditor();

	    //==============================================================================
    /** Our demo filter is a ChangeBroadcaster, and will call us back when one of
        its parameters changes.
    */
	void changeListenerCallback (ChangeBroadcaster* source);
	int changeListenerCallback (void*){return 0;};




	Knob* addNormalKnob(int x , int y ,ObxdAudioProcessor* filter, int parameter,String name,float defval);
	Knob* addTinyKnob(int x , int y ,ObxdAudioProcessor* filter, int parameter,String name,float defval);
	void placeLabel(int x , int y,String text);
	TooglableButton* addNormalTooglableButton(int x , int y , ObxdAudioProcessor* filter,int parameter,String name);
	TooglableButton* addTinyTooglableButton(int x , int y , ObxdAudioProcessor* filter,int parameter,String name);

	ButtonList* addNormalButtonList(int x , int y ,int width, ObxdAudioProcessor* filter,int parameter,String name,Image img);
    void sliderValueChanged (Slider*);
	void buttonClicked (Button *);
    void comboBoxChanged(ComboBox*);

    void updateParametersFromFilter();

    //==============================================================================
    /** Standard Juce paint callback. */
    void paint (Graphics& g);

    /** Standard Juce resize callback. */
    //void resized();
	Knob* cutoffKnob,*resonanceKnob,*osc1PitchKnob,*osc2PitchKnob,*osc2DetuneKnob,*volumeKnob,
		*portamentoKnob,*voiceDetuneKnob,*filterEnvelopeAmtKnob,*pulseWidthKnob,*xmodKnob,*multimodeKnob,*attackKnob,*decayKnob,*sustainKnob,*releaseKnob,
		*fattackKnob,*fdecayKnob,*fsustainKnob,*freleaseKnob,*osc1MixKnob,*osc2MixKnob,*noiseMixKnob,
		*filterDetuneKnob,*envelopeDetuneKnob,*portamentoDetuneKnob,
		*tuneKnob,
		*lfoFrequencyKnob,*lfoAmt1Knob,*lfoAmt2Knob,
		*pan1Knob,*pan2Knob,*pan3Knob,*pan4Knob,*pan5Knob,*pan6Knob,*pan7Knob,*pan8Knob,
		*brightnessKnob,*envPitchModKnob,
		*bendLfoRateKnob
		,*veloAmpEnvKnob,*veloFltEnvKnob,*transposeKnob;

	TooglableButton* hardSyncButton,*osc1SawButton,*osc2SawButton,*osc1PulButton,*osc2PulButton,*filterKeyFollowButton,*unisonButton,*pitchQuantButton,
		*filterHQButton,*filterBPBlendButton,
		*lfoSinButton,*lfoSquareButton,*lfoSHButton,*lfoOsc1Button,*lfoOsc2Button,*lfoFilterButton,
		*lfoPwm1Button,*lfoPwm2Button,
		*bendRangeButton,*bendOsc2OnlyButton,
	*fourPoleButton,*asPlayedAllocButton;

	ButtonList *voiceSwitch,*legatoSwitch;
    //==============================================================================
    // This is just a standard Juce paint method...
//    void paint (Graphics& g);
	ObxdAudioProcessor* getFilter() noexcept    { return (ObxdAudioProcessor*)getAudioProcessor();}
};


#endif  // PLUGINEDITOR_H_INCLUDED
