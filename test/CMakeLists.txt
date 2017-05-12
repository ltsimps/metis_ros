set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../src/Parser.cpp
    ../src/Sentiment.cpp
    ../src/NegativeSentiment.cpp
    ../src/PositiveSentiment.cpp
    ../src/SentimentService.cpp
    ../src/listener.cpp
    ../src/talker.cpp

    
    
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include ../include  ../app)
target_link_libraries(cpp-test PUBLIC gtest)
