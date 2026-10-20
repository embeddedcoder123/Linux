#include <iostream>
#include <memory>
#include <string>

// Adaptee class
class FahrenheitSensor {
    public:
        float getFahrenheitTemp() {
        float t = 32.0;
        // read temperature from hardware
        return t;
    }
};

// Target interface
class TemperatureSensor {
    public:
        virtual float getTemperature() = 0;
};

// Adapter class
class FahrenheitToCelsiusAdapter : public TemperatureSensor {
    public:
        FahrenheitToCelsiusAdapter(std::shared_ptr<FahrenheitSensor> sensor) 
          : fahrenheit_sensor_(sensor) {
        }

        float getTemperature() override {
            float fahrenheit_temp = fahrenheit_sensor_->getFahrenheitTemp();
            float celsius_temp = (fahrenheit_temp - 32.0) * 5.0 / 9.0;
            return celsius_temp;
        }

    private:
        std::shared_ptr<FahrenheitSensor> fahrenheit_sensor_;
};

int main() {
  // create an instance of the Adaptee class
  std::shared_ptr<FahrenheitSensor> fahrenheit_sensor = std::make_shared<FahrenheitSensor>();

  // create an instance of the Adapter class and pass in the Adaptee instance
  std::shared_ptr<TemperatureSensor> temperature_sensor = std::make_shared<FahrenheitToCelsiusAdapter>(fahrenheit_sensor);

  // use the Adapter's interface to get the temperature
  float temperature = temperature_sensor->getTemperature();
  std::cout << "Temperature is: " << temperature << " degrees Celsius" << std::endl;

  return 0;
}

/*
Op => 
Temperature is: 0 degrees Celsius
*/