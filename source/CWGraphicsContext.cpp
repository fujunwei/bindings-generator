#include "config.h"

#include "modules/three/CWGraphicsContext.h"
#include "modules/webgl/WebGLRenderingContext.h"
#include "modules/webgl/WebGLUniformLocation.h"
#include "modules/webgl/WebGLProgram.h"

blink::WebGLRenderingContext* blink::CWGraphicsContext::mContext = NULL;

namespace blink {
    void CWGraphicsContext::genBuffers(GLsizei count, GLuint* ids) {
	    for(int i=0; i<count; i++)
	    {
	      RefPtr<WebGLBuffer> pBuffer = mContext->createBuffer();
	      pBuffer.get()->ref();
	      ids[i] = (WebGLId) pBuffer.get();
	    }
    }

    void CWGraphicsContext::bindBuffer(GLenum type, GLuint buffer) {
	    WebGLBuffer* pBuffer = (WebGLBuffer*)buffer;
	    mContext->bindBuffer(type, pBuffer);
    }

    void CWGraphicsContext::bufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) {
        mContext->bufferData(target, size, data, usage);
    }

    void CWGraphicsContext::enableVertexAttribArray(GLuint index) {
    	 mContext->enableVertexAttribArray(index);
    }

    void CWGraphicsContext::disableVertexAttribArray(GLuint index) {
    	mContext->disableVertexAttribArray(index);
    }

    void CWGraphicsContext::vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized,
                         GLsizei stride, GLvoid* offset) {
    	 mContext->vertexAttribPointer(index, size, type, normalized, stride, (GLintptr)offset);
    }

    void CWGraphicsContext::drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* offset) {
    	 mContext->drawElements(mode, count, type, (GLintptr)offset);
    }

    void CWGraphicsContext::drawArrays(GLenum mode, GLint first, GLsizei count) {
    	mContext->drawArrays(mode, first, count);
    }

    void CWGraphicsContext::uniform1f(GLint location, GLfloat x) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform1f(ptr.get(), x);
    }

    void CWGraphicsContext::uniform1fv(GLint location, GLsizei count, const GLfloat* v) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform1fv(ptr.get(), count, v);
    }

    void CWGraphicsContext::uniform1i(GLint location, GLint x) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform1i(ptr.get(), x);
    }

    void CWGraphicsContext::uniform1iv(GLint location, GLsizei count, const GLint* v) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform1iv(ptr.get(), count, v);
    }

    void CWGraphicsContext::uniform2f(GLint location, GLfloat x, GLfloat y) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform2f(ptr.get(), x, y);
    }

    void CWGraphicsContext::uniform2fv(GLint location, GLsizei count, const GLfloat* v) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform2fv(ptr.get(), count, (const void*)v);
    }

    void CWGraphicsContext::uniform2i(GLint location, GLint x, GLint y) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform2i(ptr.get(), x, y);
    }

    void CWGraphicsContext::uniform2iv(GLint location, GLsizei count, const GLint* v) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform2iv(ptr.get(), count, (const void*)v);
    }

    void CWGraphicsContext::uniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform3f(ptr.get(), x, y, z);
    }

    void CWGraphicsContext::uniform3fv(GLint location, GLsizei count, const GLfloat* v) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform3fv(ptr.get(), count, v);
    }

    void CWGraphicsContext::uniform3i(GLint location, GLint x, GLint y, GLint z) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform3i(ptr.get(), x, y, z);
    }

    void CWGraphicsContext::uniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
    	mContext->uniform4f(ptr.get(), x, y, z, w);
    }

    void CWGraphicsContext::uniform4fv(GLint location, GLsizei count, const GLfloat* v) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
        mContext->uniform4fv(ptr.get(), count, (const void*)v);
    }

    void CWGraphicsContext::uniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
       mContext->uniform4i(ptr.get(), x, y, z, w);
    }

    void CWGraphicsContext::uniform4iv(GLint location, GLsizei count, const GLint* v) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
        mContext->uniform4iv(ptr.get(), count, (const void*)v);
    }

    void CWGraphicsContext::uniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
        mContext->uniformMatrix2fv(ptr.get(), count, transpose, value);
    }

    void CWGraphicsContext::uniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
        mContext->uniformMatrix3fv(ptr.get(), transpose, count, (const void*)value);
    }

    void CWGraphicsContext::uniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> ptr = WebGLUniformLocation::create(0, location);
        mContext->uniformMatrix4fv(ptr.get(), transpose, count, (const void*)value);
    }

    void CWGraphicsContext::useProgram(GLuint program) {
   		mContext->useProgram((WebGLProgram*)program);
    }

    GLint CWGraphicsContext::createProgram() {
		RefPtr<WebGLProgram> pProgram = mContext->createProgram();
		pProgram->ref();
    	return (GLint)(pProgram.get());
    }

    GLuint CWGraphicsContext::createShader(GLint shaderType) {
	    RefPtr<WebGLShader> pShader = mContext->createShader(shaderType);
	    pShader->ref();
	    return (GLuint)(pShader.get());
    }

    void CWGraphicsContext::shaderSource(GLint shader,   GLsizei count, const GLchar **string, const GLint *length) {
	    WebGLShader* pShader = (WebGLShader*)(shader);
	    String sourceString(string[0]);
	    for(int i = 1; i < count; i++)
	    {
	      String tempString(string[i]);
	      sourceString.append(tempString);
	    }
	    mContext->shaderSource(pShader, sourceString);
    }

    void CWGraphicsContext::compileShader(GLint shader) {
    	WebGLShader* pShader = (WebGLShader*)shader;
    	mContext->compileShader(pShader);
    }

    void CWGraphicsContext::getShaderiv(GLint shader, GLenum pname, GLint* value) {
    	//TODO
    }

    void CWGraphicsContext::getShaderInfoLog(GLint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog) {
    	String infoString = mContext->getShaderInfoLog((WebGLShader*)shader);
        *length = infoString.length() < (unsigned)maxLength ?  infoString.length() : maxLength;
         memcpy(infoLog, infoString.characters8(),(unsigned)*length);
    }

    GLint CWGraphicsContext::getUniformLocation(GLint program, const GLchar* name) {
    	PassRefPtrWillBeRawPtr<WebGLUniformLocation> location = mContext->getUniformLocation((WebGLProgram*)program, name);
    	return location->location();
    }

    GLint CWGraphicsContext::getAttribLocation(GLint program, const GLchar* name) {
    	return mContext->getAttribLocation((WebGLProgram*)program, name);
    }

    void CWGraphicsContext::attachShader(GLint program, GLint shader) {
    	mContext->attachShader((WebGLProgram*)program, (WebGLShader*)shader);
    }

    void CWGraphicsContext::bindAttribLocation(GLint program, GLuint index, const GLchar* name) {
    	mContext->bindAttribLocation((WebGLProgram*)program, index, name);
    }

    void CWGraphicsContext::linkProgram(GLint program) {
    	mContext->linkProgram((WebGLProgram*)program);
    }

    void CWGraphicsContext::deleteShader(GLint shader) {
    	mContext->deleteShader((WebGLShader*)shader);
    }

    void CWGraphicsContext::getIntegerv(GLenum pname, GLint* value) {
    	//TODO
    }

    void CWGraphicsContext::viewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    	mContext->viewport(x, y, width, height);
    }

    void CWGraphicsContext::clear(GLbitfield mask) {
    	mContext->clear(mask);
    }

    void CWGraphicsContext::clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    	mContext->clearColor(red, green, blue, alpha);
    }

    void CWGraphicsContext::disable(GLenum cap) {
    	mContext->disable(cap);
    }

    void CWGraphicsContext::enable(GLenum cap) {
    	mContext->enable(cap);
    }

    void CWGraphicsContext::frontFace(GLenum mode) {
    	mContext->frontFace(mode);
    }

    void CWGraphicsContext::cullFace(GLenum mode) {
    	mContext->cullFace(mode);
    }

    void CWGraphicsContext::depthMask(GLboolean flag) {
    	mContext->depthMask(flag);
    }

    void CWGraphicsContext::lineWidth(GLfloat width) {
    	mContext->lineWidth(width);
    }

    void CWGraphicsContext::polygonOffset(GLfloat factor, GLfloat units) {
    	mContext->polygonOffset(factor, units);
    }

    void CWGraphicsContext::blendEquation(GLenum mode) {
    	mContext->blendEquation(mode);
    }

    void CWGraphicsContext::blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
    	mContext->blendEquationSeparate(modeRGB, modeAlpha);
    }

    void CWGraphicsContext::blendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    	mContext->blendColor(red, green, blue, alpha);
    }

    void CWGraphicsContext::blendFunc(GLenum sfactor, GLenum dfactor) {
    	mContext->blendFunc(sfactor, dfactor);
    }

    void CWGraphicsContext::blendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    	mContext->blendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
    }

    void CWGraphicsContext::genTextures(GLsizei count, GLuint* ids) {
	    for(int i=0; i<count; i++)
	    {
	      RefPtr<WebGLTexture> pTexture = mContext->createTexture();
	      ids[i] = (GLuint)(pTexture.get());
	    }
    }

    void CWGraphicsContext::activeTexture(GLenum texture) {
    	mContext->activeTexture(texture);
    }

    void CWGraphicsContext::bindTexture(GLenum target, GLint texture) {
    	mContext->bindTexture(target, (WebGLTexture*)texture);
    }

    void CWGraphicsContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width,
                                             GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) {
    	// mContext->texImage2D(target, level, internalformat, format, type, String(urlString), width, height);
    	//TODO
    }

    void CWGraphicsContext::generateMipmap(GLenum target) {
    	mContext->generateMipmap(target);
    }

    void CWGraphicsContext::clearDepth(GLclampf depth) {
    	mContext->clearDepth(depth);
    }

    void CWGraphicsContext::clearStencil(GLint s) {
    	mContext->clearStencil(s);
    }

    void CWGraphicsContext::depthFunc(GLenum func) {
    	mContext->depthFunc(func);
    }

}