#pragma once

#include "OgreTexture.h"
#include "Compositor/OgreCompositorChannel.h"
#include "Compositor/OgreCompositorManager2.h"
#include "Compositor/OgreCompositorWorkspace.h"
#include "Compositor/OgreCompositorWorkspaceListener.h"
#include "MogreRenderTarget.h"
#include "MogreTextureManager.h"
#include "MogreCommon.h"
#include "STLContainerWrappers.h"
#include "IteratorWrapper.h"
#include "Marshalling.h"

namespace Mogre
{
	ref class SceneManager;
	ref class Camera;
	ref class RenderSystem;
	ref class CompositorWorkspace;
	ref class CompositorPass;

	public ref class CompositorChannel
	{
	public:
		INC_DECLARE_STLVECTOR(TextureVec, Mogre::TexturePtr^, Ogre::TexturePtr, public:, private:);

	public:
		Mogre::RenderTarget^ target;
		TextureVec^ textures;

		CompositorChannel()
		{
			textures = gcnew TextureVec();
		}

		property bool IsMrt
		{
			bool get()
			{
				return textures->Count > 1;
			}
		}

		property bool IsValid
		{
			bool get()
			{
				return target != nullptr;
			}
		}

	public protected:
		static operator CompositorChannel ^ (const Ogre::CompositorChannel& obj)
		{
			CompositorChannel^ clr = gcnew CompositorChannel;
			clr->target = obj.target;
			clr->textures = gcnew CompositorChannel::TextureVec();
			*clr->textures->_native = obj.textures;
			return clr;
		}

		static operator CompositorChannel ^ (const Ogre::CompositorChannel* pObj)
		{
			return *pObj;
		}
	};

	public ref class TextureDefinitionBase : IMogreDisposable
	{
	public:
		/// <summary>Raised before any disposing is performed.</summary>
		virtual event EventHandler^ OnDisposing;
		/// <summary>Raised once all disposing is performed.</summary>
		virtual event EventHandler^ OnDisposed;

	internal:
		Ogre::TextureDefinitionBase* _native;
		bool _createdByCLR;

	public protected:
		TextureDefinitionBase(IntPtr ptr) : _native((Ogre::TextureDefinitionBase*)ptr.ToPointer())
		{

		}

		TextureDefinitionBase(Ogre::TextureDefinitionBase* obj) : _native(obj)
		{

		}

	public:
		~TextureDefinitionBase();
	protected:
		!TextureDefinitionBase();

	public:
		property bool IsDisposed
		{
			virtual bool get()
			{
				return _native == nullptr;
			}
		}

		DEFINE_MANAGED_NATIVE_CONVERSIONS(TextureDefinitionBase);

	internal:
		property Ogre::TextureDefinitionBase* UnmanagedPointer
		{
			Ogre::TextureDefinitionBase* get();
		}
	};

	public ref class CompositorWorkspaceDef : public TextureDefinitionBase
	{
	public protected:
		CompositorWorkspaceDef(IntPtr ptr) : TextureDefinitionBase(ptr)
		{

		}

		CompositorWorkspaceDef(Ogre::CompositorWorkspaceDef* obj) : TextureDefinitionBase(obj)
		{

		}

	public:
		void Connect(String^ outNode, Ogre::uint32 outChannel, String^ inNode, Ogre::uint32 inChannel);
		void Connect(String^ outNode, String^ inNode);
		void ConnectOutput(String^ inNode, Ogre::uint32 inChannel);
		void ClearAllInterNodeConnections();
		void ClearOutputConnections();
		void ClearAll();
		void AddNodeAlias(String^ alias, String^ nodeName);
		void RemoveNodeAlias(String^ alias);

		DEFINE_MANAGED_NATIVE_CONVERSIONS(CompositorWorkspaceDef);

	internal:
		property Ogre::CompositorWorkspaceDef* UnmanagedPointer
		{
			Ogre::CompositorWorkspaceDef* get();
		}
	};

	public interface class ICompositorWorkspaceListener
	{
		virtual Ogre::CompositorWorkspaceListener* _GetNativePtr();
	public:
		virtual void WorkspacePreUpdate(Mogre::CompositorWorkspace^ workspace);
		//virtual void PassPreExecute(Mogre::CompositorPass^ pass);
	};

	public ref class CompositorWorkspaceListener : public IMogreDisposable, public Mogre::ICompositorWorkspaceListener
	{
	public:
		/// <summary>Raised before any disposing is performed.</summary>
		virtual event EventHandler^ OnDisposing;
		/// <summary>Raised once all disposing is performed.</summary>
		virtual event EventHandler^ OnDisposed;

	internal:
		Ogre::CompositorWorkspaceListener* _native;
		bool _createdByCLR;

	public protected:
		CompositorWorkspaceListener(Ogre::CompositorWorkspaceListener* obj) : _native(obj)
		{
		}

		virtual Ogre::CompositorWorkspaceListener* _IListener_GetNativePtr() = ICompositorWorkspaceListener::_GetNativePtr;
	public:
		CompositorWorkspaceListener();

	public:
		~CompositorWorkspaceListener();
	protected:
		!CompositorWorkspaceListener();

	public:
		virtual void WorkspacePreUpdate(Mogre::CompositorWorkspace^ workspace);
		//virtual void PassPreExecute(Mogre::CompositorPass^ pass);

		property bool IsDisposed
		{
			virtual bool get()
			{
				return _native == nullptr;
			}
		}
	};

	public ref class CompositorWorkspace : IMogreDisposable
	{
	public:
		/// <summary>Raised before any disposing is performed.</summary>
		virtual event EventHandler^ OnDisposing;
		/// <summary>Raised once all disposing is performed.</summary>
		virtual event EventHandler^ OnDisposed;

	internal:
		Ogre::CompositorWorkspace* _native;
		bool _createdByCLR;
		Mogre::ICompositorWorkspaceListener^ _listener;

	public protected:
		CompositorWorkspace(IntPtr ptr) : _native((Ogre::CompositorWorkspace*)ptr.ToPointer()), _listener(nullptr)
		{

		}

		CompositorWorkspace(Ogre::CompositorWorkspace* obj) : _native(obj), _listener(nullptr)
		{

		}

	public:
		~CompositorWorkspace();
	protected:
		!CompositorWorkspace();

	public:
		property bool IsDisposed
		{
			virtual bool get()
			{
				return _native == nullptr;
			}
		}

		property bool Enabled
		{
		public:
			bool get();
		public:
			void set(bool enabled);
		}

		void SetListener(Mogre::ICompositorWorkspaceListener^ listener);
		Mogre::ICompositorWorkspaceListener^ GetListener();

		void RecreateAllNodes();
		void ReconnectAllNodes();

		void _beginUpdate(bool forceBeginFrame);
		void _update();
		void _endUpdate(bool forceEndFrame);
		void _swapFinalTarget();
		void _validateFinalTarget();

		DEFINE_MANAGED_NATIVE_CONVERSIONS(CompositorWorkspace);

	internal:
		property Ogre::CompositorWorkspace* UnmanagedPointer
		{
			Ogre::CompositorWorkspace* get();
		}
	};

	public ref class CompositorManager2 : IMogreDisposable
	{
	public:
		/// <summary>Raised before any disposing is performed.</summary>
		virtual event EventHandler^ OnDisposing;
		/// <summary>Raised once all disposing is performed.</summary>
		virtual event EventHandler^ OnDisposed;

	internal:
		Ogre::CompositorManager2* _native;
		bool _createdByCLR;

	public protected:
		CompositorManager2(Ogre::CompositorManager2* obj) : _native(obj)
		{
		}

		CompositorManager2(IntPtr ptr) : _native((Ogre::CompositorManager2*)ptr.ToPointer())
		{

		}

	public:
		~CompositorManager2();
	protected:
		!CompositorManager2();

	public:
		CompositorManager2(RenderSystem^ renderSystem);

		bool HasNodeDefinition(String^ nodeDefName);

		bool HasWorkspaceDefinition(String^ name);
		CompositorWorkspaceDef^ GetWorkspaceDefinition(String^ name);
		CompositorWorkspaceDef^ AddWorkspaceDefinition(String^ name);

		void CreateBasicWorkspaceDef(String^ name, ColourValue backgroundColor);

		CompositorWorkspace^ AddWorkspace(SceneManager^ sceneManager, RenderTarget^ finalRenderTarget, Camera^ defaultCamera, String^ definitionName);
		CompositorWorkspace^ AddWorkspace(SceneManager^ sceneManager, RenderTarget^ finalRenderTarget, Camera^ defaultCamera, String^ definitionName, bool enabled);
		CompositorWorkspace^ AddWorkspace(SceneManager^ sceneManager, RenderTarget^ finalRenderTarget, Camera^ defaultCamera, String^ definitionName, bool enabled, int position);

		CompositorWorkspace^ AddWorkspace(SceneManager^ sceneManager, CompositorChannel^ finalRenderTarget, Camera^ defaultCamera, String^ definitionName);
		CompositorWorkspace^ AddWorkspace(SceneManager^ sceneManager, CompositorChannel^ finalRenderTarget, Camera^ defaultCamera, String^ definitionName, bool enabled);
		CompositorWorkspace^ AddWorkspace(SceneManager^ sceneManager, CompositorChannel^ finalRenderTarget, Camera^ defaultCamera, String^ definitionName, bool enabled, int position);

		void RemoveWorkspace(CompositorWorkspace^ workspace);
		void RemoveAllWorkspaces();
		void RemoveAllWorkspaceDefinitions();

		property bool IsDisposed
		{
			virtual bool get()
			{
				return _native == nullptr;
			}
		}

		DEFINE_MANAGED_NATIVE_CONVERSIONS(CompositorManager2);

	internal:
		property Ogre::CompositorManager2* UnmanagedPointer
		{
			Ogre::CompositorManager2* get();
		}
	};
}