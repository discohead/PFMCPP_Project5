#include <iostream>
/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

 Destructors
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 6) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 copied UDT 1:
 */
struct Oscillator
{
    float frequency = 440.0;
    float phase = 0.0;
    float amplitude = 1.0;
    unsigned int waveType = 0;

    void play();
    void stop()
    {
        std::cout << "STOP" << std::endl;
    }
    
    ~Oscillator()
    {
        std::cout << "Oscillator" << std::endl;
    }
};
/*
 copied UDT 2:
 */
struct Envelope
{
    float attack = 0.1f;
    float decay = 0.1f;
    float sustain = 1.0f;
    float release = 0.5f;
    float amplitude = 1.0f;

    void trigger();
    void reset()
    {
        std::cout << "RESET" << std::endl;
    }
    
    ~Envelope()
    {
        std::cout << "Envelope" << std::endl;
    }
};
/*
 copied UDT 3:
 */
struct Lamp
{
    bool on = false;

    struct Bulb
    {
        float brightness = 100.0f;
        float warmth = 0.5f;
    };

    void changeBulb(Bulb bulb);
    void flipSwitch();
    
    ~Lamp()
    {
        std::cout << "Lamp" << std::endl;
    }
};
/*
 new UDT 4:
 */
struct ComplexOscillator
{
    Oscillator primaryOsc;
    Oscillator modulatorOsc;
    
    void play()
    {
        primaryOsc.play();
        modulatorOsc.play();
    }
    void stop()
    {
        primaryOsc.stop();
        modulatorOsc.stop();
    }
    
    ~ComplexOscillator()
    {
        std::cout << "ComplexOscillator" << std::endl;
        stop();
    }
};
/*
 new UDT 5:
 */
struct Synthesizer
{
    ComplexOscillator oscillator;
    Envelope filterEnv;
    Envelope ampEnv;
    
    ~Synthesizer()
    {
        std::cout << "Synthesizer" << std::endl;
        filterEnv.reset();
        ampEnv.reset();
    }
};

int main()
{
    ComplexOscillator cOsc = ComplexOscillator();
    Synthesizer synth = Synthesizer();
    std::cout << "good to go!" << std::endl;
}
