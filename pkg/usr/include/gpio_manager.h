/**
 * @file gpio_manager.h
 * @author Lukas L. Moreira
 * @brief Header for GPIO management in ROCK 5C. 
 * 
 * This file contains the declarations for mapping and managing GPIO pins.
 * 
 * @version 1.0
 * @date 2026-01-02
 * 
 * @copyright Copyright (c) 2026 Lukas L. Moreira
 * 
 */

#pragma once

#include <mutex>
#include <string>
#include <iostream>

using namespace std;

namespace rock5c {  

    /**
     * @brief Class for managing GPIO pins using Singleton pattern.
     * @author Lukas L. Moreira
     * 
     * @date 2026-01-02
     * @copyright Copyright (c) 2026 Lukas L. Moreira
     * 
     */
    class GPIO_manager {

        private:
            static mutex mutex_;
            static GPIO_manager* pinstance_;

        protected:
            string value_;
            GPIO_manager(const string value): value_(value) {}    
            ~GPIO_manager() {}
        
        public:

            GPIO_manager(GPIO_manager &other) = delete;
            void operator=(const GPIO_manager &) = delete;
            static GPIO_manager* getInstance(const string& value);

            string getValue() const {
                return value_;
            }
 
            void definePins();
    };
}