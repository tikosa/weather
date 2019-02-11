# Clone the repo
 mkdir -p /home/tigran/dev/
 cd /home/tigran/dev/
 git clone https://github.com/tikosa/weather.git
 cd weather
 git submodule update --init --recursive

# Build Weather
 mkdir -p /home/tigran/dev/weather_build
 cd /home/tigran/dev/weather_build/
 cmake /home/tigran/dev/weather
 cmake --build . --target all -- -j -l 2.0
