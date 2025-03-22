set(LIBRARY_SOURCES
        Derived1.cpp
        Base.cpp
        Derived2.cpp
        DerivedDerived.cpp
)

add_library(${LIBRARY_NAME} STATIC
        ${LIBRARY_SOURCES}
)

target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

#target_link_libraries(${LIBRARY_NAME} PRIVATE
#)




