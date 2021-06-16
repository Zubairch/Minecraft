#pragma once

#include <MC.h>

#include "Error.h"
#include "VertexArray.h"

namespace Minecraft { namespace API {

	class RenderCommand {

	public:
		RenderCommand() = delete;
		~RenderCommand() = delete;

		inline static void ClearColor(const glm::vec4& color = { 0.3f, 0.3f, 0.4f, 1.0f }) {

			GLCall(glClearColor(color.r, color.g, color.b, color.a))
		}

		inline static void Clear(GLbitfield mask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) {

			GLCall(glClear(mask))
		}

		inline static void DepthTest(bool val) {
		
			if (val) {

				GLCall(glEnable(GL_DEPTH_TEST))
			}
			else {

				GLCall(glDisable(GL_DEPTH_TEST))
			}
		}

		inline static void CullFace(bool val) {

			if (val) {

				GLCall(glEnable(GL_CULL_FACE))
				GLCall(glFrontFace(GL_CW))
				GLCall(glCullFace(GL_BACK))
			}
			else {

				GLCall(glDisable(GL_CULL_FACE))
			}
		}

		inline static void DepthFunction(GLenum function) {

			GLCall(glDepthFunc(function))
		}

		inline static void DrawIndexed(const API::VertexArray& vertexArray) {

			vertexArray.Bind();
			GLCall(glDrawElements(GL_TRIANGLES, vertexArray.GetCount(), GL_UNSIGNED_INT, GL_ZERO))
		}

		inline static void SetViewPort(int width, int heigth) {

			GLCall(glViewport(0, 0, width, heigth))
		}

		inline static void Draw(const API::VertexArray& vertexArray) {

			vertexArray.Bind();
			GLCall(glDrawArrays(GL_TRIANGLES, GL_ZERO, vertexArray.GetCount()))
		}
	};
} }