#include <iostream>
#include <string>

using namespace std;

class TemperatureSensor{
    private:
        double temperature;
    public:
         class TemperatureOutOfRange{
            private: 
                string msg;
            public: 
                TemperatureOutOfRange(string m): msg(m){};

                string getMsg() const {
                    return msg; 
                }
        };
    


        TemperatureSensor(double t): temperature(t){};

        void readTemperature() {
            if (temperature < -50 || temperature > 150){
                throw TemperatureOutOfRange("Temperature is out of range");
            }
        }

};


int main(){

    try{
        TemperatureSensor t1(1);
        TemperatureSensor t2(300);

        t1.readTemperature();
        t2.readTemperature();
    }
    catch (const string& e) {
        cout << e << endl;
    }
    catch (const TemperatureSensor::TemperatureOutOfRange& e) {
        cout << e.getMsg() << endl;
    }      



    return 0;
}