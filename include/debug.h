//
// Created by ASUS on 30.04.2024.
//

#ifndef UNTITLED2_DEBUG_H
#define UNTITLED2_DEBUG_H

#ifdef DEBUG
#define DEBUG_LOG(a) printf("DEBUG: Info: %s\n", a)
#define DEBUG_WARNING(a) printf("DEBUG: Warning: %s\n", a)
#define DEBUG_ERROR(a) printf("DEBUG: Error: %s\n", a)
#endif
#ifndef DEBUG
#define DEBUG_LOG(a) a
#define DEBUG_WARNING(a) a
#define DEBUG_ERROR(a) a
#endif

#endif //UNTITLED2_DEBUG_H
