#include <iostream>
#include <thread>   // For sleep function
#include <chrono>   // For time delay

using namespace std;

// Traffic Signal Class
class TrafficSignal {
private:
    string signalColor;

public:
    TrafficSignal() {
        signalColor = "Red"; // Default signal is Red
    }

    // Function to change signal
    void changeSignal() {
        if (signalColor == "Red") {
            signalColor = "Green";
        } else if (signalColor == "Green") {
            signalColor = "Yellow";
        } else {
            signalColor = "Red";
        }
    }

    // Function to display current signal
    void displaySignal() {
        cout << "\n🚦 Current Signal: " << signalColor << " 🚦\n";

        if (signalColor == "Red") {
            cout << "🛑 Stop! Wait for Green light.\n";
        } else if (signalColor == "Yellow") {
            cout << "⚠️  Get Ready to Move!\n";
        } else {
            cout << "✅ Go! Drive safely.\n";
        }
    }

    // Function to run the signal system
    void runSignalSystem() {
        for (int i = 0; i < 5; i++) {  // Running 5 cycles of signals
            displaySignal();
            this_thread::sleep_for(chrono::seconds(3)); // Delay for 3 seconds
            changeSignal();
        }
        cout << "\n🚦 Traffic Signal System Stopped 🚦\n";
    }
};

// Main function
int main() {
    TrafficSignal signal;

    cout << "\n===== Traffic Signal System Started =====\n";

    signal.runSignalSystem();

    cout << "\n===== Traffic Signal System Ended =====\n";
    return 0;
}