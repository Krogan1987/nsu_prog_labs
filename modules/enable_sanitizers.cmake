if(ENABLE_ASAN)
	target_compile_options(${PROJECT_NAME} PUBLIC -O1)
	target_compile_options(${PROJECT_NAME} PUBLIC -fno-omit-frame-pointer)
	target_compile_options(${PROJECT_NAME} PUBLIC -fsanitize=address)
	target_compile_options(${PROJECT_NAME} PUBLIC -fsanitize=leak)
endif()

if(ENABLE_USAN)
	target_compile_options(${PROJECT_NAME} PUBLIC -fsanitize=undefined)
endif()

if(ENABLE_TSAN)
	target_compile_options(${PROJECT_NAME} PUBLIC -fsanitize=thread)
endif()
