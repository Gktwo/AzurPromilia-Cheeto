#include "pch.h"
#include "renderer.h"

#include "backend/dx11_backend.h"

Renderer& Renderer::getInstance()
{
    static Renderer instance;
    return instance;
}

Renderer::~Renderer()
{
    shutdown();
}

bool Renderer::initialize()
{
    if (m_initialized) return true;

    // Auto-detect render API
    RenderAPI detectedAPI = utils::DXUtils::getRenderAPI();
    
    if (detectedAPI == RenderAPI::Unknown)
    {
        LOG_ERROR("Unable to detect rendering API");
        return false;
    }

    LOG_INFO("Detected rendering API: {}", magic_enum::enum_name(detectedAPI).data());
    return initialize(detectedAPI);
}

bool Renderer::initialize(RenderAPI api)
{
    if (m_initialized) return true;

    if (api == RenderAPI::Unknown) return false;


    // Create appropriate backend
    m_backend = createBackend(api);
    if (!m_backend) return false;


    // Initialize backend
    if (!m_backend->initialize())
    {
        m_backend.reset();
        return false;
    }

    m_currentAPI = api;
    m_initialized = true;

    return true;
}

void Renderer::shutdown()
{
    if (!m_initialized) return;

    if (m_backend)
    {
        m_backend->shutdown();
        m_backend.reset();
    }

    m_currentAPI = RenderAPI::Unknown;
    m_initialized = false;
}

void Renderer::onResize(int width, int height)
{
    if (m_initialized && m_backend) m_backend->onResize(width, height);
}

std::unique_ptr<IRendererBackend> Renderer::createBackend(RenderAPI api)
{
    switch (api)
    {
        case RenderAPI::DirectX11:
            return std::make_unique<DX11Backend>();
        case RenderAPI::DirectX12:
        default:
            return nullptr;
    }
}
