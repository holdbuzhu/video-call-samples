#pragma once

#include "VideoRenderWindow.h"

class LocalVideoWindow : public VideoRenderWindow
{
public:
    using OnDestroyObserver = std::function<void(void)>;

    void setOnDestroyObserver(OnDestroyObserver observer)
    {
        m_observer = std::move(observer);
    }

protected:
    void OnWindowCreate() override
    {
        SetWindowTitle("Local Video");
    }

    LRESULT OnWindowDestroy() override
    {
        if (m_observer) {
            m_observer();
        }
        return 0;
    }

protected:
    OnDestroyObserver m_observer;
};

