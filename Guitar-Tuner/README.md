### Hello, I built a guitar tuner with javascript. Here it is ###

I wanted to get better at Javascript and get a basic hang of UI. I also found it a great way to incorporate the ideas from my circuits course about filters and performing FFTs. 

This isn't the final code (as of Aug9, 2025) but I want to fix it. I'm running into issues where it won't differentiate between E2 and E3/4/5, and has a hard time picking up notes after C#2. 

I created this because I got really frustrated with online tuners when I wanted to change my tuning setup from standard to something like Drop C# or Drop B. The phone tuners have a such a hard time picking it up and I thought I could do better AND learn something in the meantime. 

While I do have a lot more to fix and refine in this code, and ideas to use C++ and Juce in the future, here's how it all comes together...

**Features:**

I used the Javascript Web Audio API for live audio input. It lets you choose which microphone input and has some echoCancellation/noiseSuppression/autoGainControl for cleaner signals.

I used Mcleod Pitch Method (MPM) (a method used for finding the fundemental frequency of a sound from its waveform, here's a nice article about it https://www.cs.otago.ac.nz/graphics/Geoff/tartini/papers/A_Smarter_Way_to_Find_Pitch.pdf  )

DC Removal is to remove constant offset and set the waveform's center as close to one, and Hann Window allows the computer not to recognize the edges (when you pluck and let go) which are huge changes compared to the actual note)

Normalized Square Difference Function (NSDF) is a vital part of MPM since it shows where the waveform is a perfect *shifted* copy of itself... Parabolic interpolation is where the algorithm finds the highest peak of NSDF and fits a parabola on that to find the exact pitch between discrete sample steps.

The tuner has an adaptive analysis for larger frames (8192 samples) for lower strings and smaller frames (4096 samples) for higher strings.

I added a feature to select which string you'd like to tune. Online tuners always annoyed me when they would misrecognize strings, especially when you're going down from standard to dropped tunings. 
