#pragma once

namespace yg
{
  namespace gl
  {
    class VertexBuffer
    {
    private:

      unsigned int m_id;
      unsigned int m_size;
      void * m_gpuData;

      /// using VA instead of buffer objects on some old GPU's
      bool m_useVA;

    public:

      VertexBuffer(bool useVA);
      VertexBuffer(size_t size, bool useVA);
      ~VertexBuffer();

      void resize(size_t size);
      size_t size() const;

      void makeCurrent();
      void * lock();
      void unlock();
      void * glPtr() const;

      static unsigned current();
    };
  }
}
