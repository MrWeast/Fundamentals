# Description
- this repo is for me to demo some fundamentals on various topics
  - Topics I aim to include:
    - Algorithms
    - Data Structures
    - Machine Learning
    - more??

# documentation
- navigate to the root directory of this project and run:
  - doxygen Doxyfile
- this will build a web page in a new subdirectory /html, open /html/index.html in a browser to see more project documentation
# Data Structure Building
- if you want to try out a specific data structure, navigate to the appropriate subdirectory then run:
  - mkdir build
  - cd build
  - cmake ..
  - make
- then run the appropriate executable
# Data Structure Testing
- follow the steps desribed in Data Structure Building, then run:
  - ctest
- this will run tests to make sure the data structures within the subdirectory are working as expected

