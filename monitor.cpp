#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void displayAlertMessage(void) {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

int is_in_range(float value, float min_value, float max_value, const char* message) {
  if (value < min_value || value > max_value) {
    cout << message << "\n";
    displayAlertMessage();
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return (is_in_range(temperature, 95, 102, "Temperature is critical!") &&
  is_in_range(pulseRate, 60, 100, "Pulse Rate is out of range!") &&
  is_in_range(spo2, 90, 100, "Oxygen Saturation out of range!") );
}
