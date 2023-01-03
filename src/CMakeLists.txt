set(src_files 
    BMPFileContent.hpp
    BMPImage.hpp
    BMPImage.cpp
    ImageReader.hpp
    ImageReader.cpp
    ImageWriter.hpp
    ImageWriter.cpp
    ImageProcessor.hpp
    ImageProcessor.cpp
    Filters.hpp
    Filters.cpp
    Convolver.hpp
    Convolver.cpp
    Matrix.hpp
    Matrix.cpp
    main.cpp
)

add_executable(src ${src_files})
set_property(TARGET src PROPERTY CXX_STANDARD 20)
target_link_libraries(src headers)
target_link_libraries(src libiris.so)