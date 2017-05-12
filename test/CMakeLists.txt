set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../app/Parser.cpp
    ../app/Sentiment.cpp
    ../app/NegativeSentiment.cpp
    ../app/PositiveSentiment.cpp
    
    
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include ../include  ../app)
target_link_libraries(cpp-test PUBLIC gtest)
