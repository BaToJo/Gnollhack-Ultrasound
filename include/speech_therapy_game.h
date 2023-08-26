﻿#pragma once
#include "hack.h"

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

// WARNING! This was written for Windows and will not work under other operating systems without modification!
// This relies on a Windows Named Pipe for interprocess communication, and it assumes it is always run on Windows.
// Please modify this to add support for interprocess communication on other operating systems.


#define PIPE_NAME "\\\\.\\pipe\\articulate_assistant_pipe_game"
#define BUFFER_SIZE 1024
#define MESSAGE_TYPE unsigned char

typedef struct {
    HANDLE pipeHandle;
    bool isConnected;
} NamedPipe;

static NamedPipe* instance = NULL;

NamedPipe* speechTherapyGame_getPipe() {
    // If the pipe struct has not been instantiated yet, create it.
    if (instance == NULL) {
        // You("see there is no pipe instance, so you create one.");
        instance = (NamedPipe*)malloc(sizeof(NamedPipe));
        instance->isConnected = false;
    }
    // If the pipe has not been connected yet, connect it.
    if (!instance->isConnected)
    {
        // You("see the pipe is not connected, so you try to connect to it.");
        instance->pipeHandle = CreateFile(
            PIPE_NAME,
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            0,
            NULL
        );
        auto error = GetLastError();

        if (instance->pipeHandle == INVALID_HANDLE_VALUE) {
            instance->isConnected = false;
            You("fail to connect to the pipe! (%d)", error);
            return NULL;
        } else
        {
            instance->isConnected = true;
            // You("successfully connect to the pipe.");
        }
    }
    return instance;
}

bool speechTherapyGame_sendString(const char* message) {
    if (speechTherapyGame_getPipe() != NULL)
    {
        // You("try to write to the pipe...");
        DWORD bytesWritten;
        bool result = WriteFile(
            speechTherapyGame_getPipe()->pipeHandle,
            message,
            strlen(message) + 1,
            &bytesWritten,
            NULL
        );
        auto error = GetLastError();
        if (result == true)
        {
            // You("successfully write to the pipe.");
        }
        else
        {
            You("fail to write to the pipe! (%d)", error);
        }
        return result;
    }
    return false;
}

bool speechTherapyGame_receiveString(char* buffer, DWORD bufferSize) {
    if (speechTherapyGame_getPipe() != NULL)
    {
        // You("try to read from the pipe...");
        DWORD bytesRead;
        BOOL result = ReadFile(
            speechTherapyGame_getPipe()->pipeHandle,
            buffer,
            bufferSize,
            &bytesRead,
            NULL
        );
        auto error = GetLastError();
        if (result == true)
        {
            // You("successfully read from the pipe.");
        }
        else
        {
            You("fail to read from the pipe! (%d)", error);
        }
        return result;
    }
    return false;
}

bool speechTherapyGame_sendByte(const MESSAGE_TYPE byte) {
    if (speechTherapyGame_getPipe() != NULL)
    {
        //You("try to write to the pipe...");
        DWORD bytesWritten;
        bool result = WriteFile(
            speechTherapyGame_getPipe()->pipeHandle,
            byte,
            2,
            &bytesWritten,
            NULL
        );
        auto error = GetLastError();
        if (result == true)
        {
            //You("successfully write to the pipe.");
        }
        else
        {
            You("fail to write to the pipe! (%d)",error);
        }
        return result;
    }
    return false;
}

bool speechTherapyGame_receiveByte(MESSAGE_TYPE* byte) {
    if (speechTherapyGame_getPipe() != NULL)
    {
        //You("try to read from the pipe...");
        DWORD bytesRead;
        BOOL result = ReadFile(
            speechTherapyGame_getPipe()->pipeHandle,
            byte,
            sizeof(MESSAGE_TYPE) + 1,
            &bytesRead,
            NULL
        );
        auto error = GetLastError();
        if (result == true)
        {
            //You("successfully read from the pipe.");
        }
        else
        {
            You("fail to read from the pipe! (%d)", error);
        }
        return result;
    }
    return false;
}

void speechTherapyGame_closePipe() {
    // You("try to close the pipe...");
    if (instance != NULL) {
        if (instance->isConnected) {
            speechTherapyGame_sendString("C"); // This is the shutdown signal we send to AAA to declare we are closing on this end.
            CloseHandle(instance->pipeHandle);
            instance->isConnected = FALSE;
        }
        free(instance);
        instance = NULL;
        // You("successfully close the pipe.");
    } else
    {
        You("find that the pipe is already closed! Why?");
    }
}

//int main() {
//    NamedPipe* pipe = speechTherapyGame_getPipe();
//
//    if (speechTherapyGame_sendString("Hello, named pipe!")) {
//        printf("Message sent successfully.\n");
//
//        char buffer[BUFFER_SIZE];
//        if (speechTherapyGame_receiveString(buffer, BUFFER_SIZE)) {
//            printf("Received: %s\n", buffer);
//        }
//        else {
//            printf("Failed to receive.\n");
//        }
//    }
//    else {
//        printf("Failed to send.\n");
//    }
//
//    speechTherapyGame_closePipe();
//
//    return 0;
//}



/*

#define PIPE_NAME "\\\\.\\pipe\\articulate_assistant_pipe_game"

// This class is a singleton. I chose this because I want the pipe handler to manage its own lifetime and ensure only a single instance of itself can exist.

typedef struct {
    HANDLE pipeHandle; // The object that maintains the Windows Named Pipe connection.
    bool connected; // Has a connection been established to another process using the pipe?
} NamedPipeSingleton;

// Only a single instance of the pipe should exist.
static NamedPipeSingleton instance = { INVALID_HANDLE_VALUE, false };

NamedPipeSingleton* speechTherapyGame_get_pipe() {
    return &instance;
}

bool speechTherapyGame_connect_to_pipe() {
    if (instance.connected)
    {
        return true;
    } else {
        instance.pipeHandle = CreateFileA(
            PIPE_NAME,
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            0,
            NULL
        );

        if (instance.pipeHandle == INVALID_HANDLE_VALUE) {
            You("try and fail to connect to the pipe.");
            return false;
        }

        instance.connected = true;
        return true;
    }
}

void NamedPipeSingleton_sendData(const char* data) {
    if (!instance.connected) {
        speechTherapyGame_connect_to_pipe();
    }

    DWORD bytesWritten;
    WriteFile(instance.pipeHandle, data, (DWORD)strlen(data), &bytesWritten, NULL);
}

void NamedPipeSingleton_disconnect() {
    if (instance.connected) {
        CloseHandle(instance.pipeHandle);
        instance.connected = false;
    }
}

//int main() {
//    NamedPipeSingleton* pipeSingleton = NamedPipeSingleton_getInstance();
//
//    if (NamedPipeSingleton_connect(pipeSingleton)) {
//        NamedPipeSingleton_sendData(pipeSingleton, "Hello, named pipe!");
//        NamedPipeSingleton_disconnect(pipeSingleton);
//    }
//
//    return 0;
//}


*/