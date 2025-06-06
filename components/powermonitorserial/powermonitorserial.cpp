#include "powermonitorserial.h"
#include "esphome/core/log.h"

namespace esphome {
namespace serial {

static const char *TAG = "powermonitorserial";

void PowerMonitorSerial::loop() {
  while (this->available()) {
    uint8_t c;
    this->read_byte(&c);
    if (c == '\r')
      continue;
    if (c == '\n')
      this->parse_values_();
    else
      this->rx_message_.push_back(c);
  }
}

void PowerMonitorSerial::parse_values_() {
  std::string s(this->rx_message_.begin(), this->rx_message_.end());
  int spos = 0;
  int epos = 0;
  std::vector<float> values;
  while (epos != std::string::npos) {
    epos = s.find(' ', spos);
    int len = (epos == std::string::npos ? s.size() - spos : epos - spos);
    float val = parse_number<float>(s.substr(spos, len)).value_or(NAN);
    
    // Apply the filter: report 0 if value < 105
    if (!std::isnan(val) && val < 105.0f) {
      val = 0.0f;
    }

    values.push_back(val);
    if (epos != std::string::npos)
      spos = epos + 1;
  }
  this->rx_message_.clear();
  for (auto sens : this->sensors_) {
    if (sens.first < values.size())
      sens.second->publish_state(values[sens.first]);
  }
}

void PowerMonitorSerial::dump_config() {
  ESP_LOGCONFIG("", "Power Monitor Serial");
  for (auto sens : this->sensors_) {
    ESP_LOGCONFIG(TAG, "Index %d", sens.first);
    LOG_SENSOR(TAG, "", sens.second);
  }
}

}  // namespace serial
}  // namespace esphome
