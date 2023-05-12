/*** Autogenerated by WIDL 8.2 from include/windows.gaming.ui.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __windows_gaming_ui_h__
#define __windows_gaming_ui_h__

#ifndef __WIDL_INLINE
#if defined(__cplusplus) || defined(_MSC_VER)
#define __WIDL_INLINE inline
#elif defined(__GNUC__)
#define __WIDL_INLINE __inline__
#endif
#endif

/* Forward declarations */

#ifndef ____x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_FWD_DEFINED__
#define ____x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_FWD_DEFINED__
typedef interface __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics;
#ifdef __cplusplus
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics ABI::Windows::Gaming::UI::IGameBarStatics
namespace ABI {
    namespace Windows {
        namespace Gaming {
            namespace UI {
                interface IGameBarStatics;
            }
        }
    }
}
#endif /* __cplusplus */
#endif

#ifndef ____x_ABI_CWindows_CGaming_CUI_CGameBar_FWD_DEFINED__
#define ____x_ABI_CWindows_CGaming_CUI_CGameBar_FWD_DEFINED__
#ifdef __cplusplus
namespace ABI {
    namespace Windows {
        namespace Gaming {
            namespace UI {
                class GameBar;
            }
        }
    }
}
#else
typedef struct __x_ABI_CWindows_CGaming_CUI_CGameBar __x_ABI_CWindows_CGaming_CUI_CGameBar;
#endif /* defined __cplusplus */
#endif /* defined ____x_ABI_CWindows_CGaming_CUI_CGameBar_FWD_DEFINED__ */

/* Headers for imported files */

#include <inspectable.h>
#include <eventtoken.h>
#include <windowscontracts.h>
#include <windows.foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * IGameBarStatics interface
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000
#ifndef ____x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_INTERFACE_DEFINED__
#define ____x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_INTERFACE_DEFINED__

DEFINE_GUID(IID___x_ABI_CWindows_CGaming_CUI_CIGameBarStatics, 0x1db9a292, 0xcc78, 0x4173, 0xbe,0x45, 0xb6,0x1e,0x67,0x28,0x3e,0xa7);
#if defined(__cplusplus) && !defined(CINTERFACE)
} /* extern "C" */
namespace ABI {
    namespace Windows {
        namespace Gaming {
            namespace UI {
                MIDL_INTERFACE("1db9a292-cc78-4173-be45-b61e67283ea7")
                IGameBarStatics : public IInspectable
                {
                    virtual HRESULT STDMETHODCALLTYPE add_VisibilityChanged(
                        ABI::Windows::Foundation::IEventHandler<IInspectable* > *handler,
                        EventRegistrationToken *token) = 0;

                    virtual HRESULT STDMETHODCALLTYPE remove_VisibilityChanged(
                        EventRegistrationToken token) = 0;

                    virtual HRESULT STDMETHODCALLTYPE add_IsInputRedirectedChanged(
                        ABI::Windows::Foundation::IEventHandler<IInspectable* > *handler,
                        EventRegistrationToken *token) = 0;

                    virtual HRESULT STDMETHODCALLTYPE remove_IsInputRedirectedChanged(
                        EventRegistrationToken token) = 0;

                    virtual HRESULT STDMETHODCALLTYPE get_Visible(
                        boolean *value) = 0;

                    virtual HRESULT STDMETHODCALLTYPE get_IsInputRedirected(
                        boolean *value) = 0;

                };
            }
        }
    }
}
extern "C" {
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics, 0x1db9a292, 0xcc78, 0x4173, 0xbe,0x45, 0xb6,0x1e,0x67,0x28,0x3e,0xa7)
#endif
#else
typedef struct __x_ABI_CWindows_CGaming_CUI_CIGameBarStaticsVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This);

    /*** IInspectable methods ***/
    HRESULT (STDMETHODCALLTYPE *GetIids)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        ULONG *iidCount,
        IID **iids);

    HRESULT (STDMETHODCALLTYPE *GetRuntimeClassName)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        HSTRING *className);

    HRESULT (STDMETHODCALLTYPE *GetTrustLevel)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        TrustLevel *trustLevel);

    /*** IGameBarStatics methods ***/
    HRESULT (STDMETHODCALLTYPE *add_VisibilityChanged)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        __FIEventHandler_1_IInspectable *handler,
        EventRegistrationToken *token);

    HRESULT (STDMETHODCALLTYPE *remove_VisibilityChanged)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        EventRegistrationToken token);

    HRESULT (STDMETHODCALLTYPE *add_IsInputRedirectedChanged)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        __FIEventHandler_1_IInspectable *handler,
        EventRegistrationToken *token);

    HRESULT (STDMETHODCALLTYPE *remove_IsInputRedirectedChanged)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        EventRegistrationToken token);

    HRESULT (STDMETHODCALLTYPE *get_Visible)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        boolean *value);

    HRESULT (STDMETHODCALLTYPE *get_IsInputRedirected)(
        __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics *This,
        boolean *value);

    END_INTERFACE
} __x_ABI_CWindows_CGaming_CUI_CIGameBarStaticsVtbl;

interface __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics {
    CONST_VTBL __x_ABI_CWindows_CGaming_CUI_CIGameBarStaticsVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_AddRef(This) (This)->lpVtbl->AddRef(This)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_Release(This) (This)->lpVtbl->Release(This)
/*** IInspectable methods ***/
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetIids(This,iidCount,iids) (This)->lpVtbl->GetIids(This,iidCount,iids)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetRuntimeClassName(This,className) (This)->lpVtbl->GetRuntimeClassName(This,className)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetTrustLevel(This,trustLevel) (This)->lpVtbl->GetTrustLevel(This,trustLevel)
/*** IGameBarStatics methods ***/
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_add_VisibilityChanged(This,handler,token) (This)->lpVtbl->add_VisibilityChanged(This,handler,token)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_remove_VisibilityChanged(This,token) (This)->lpVtbl->remove_VisibilityChanged(This,token)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_add_IsInputRedirectedChanged(This,handler,token) (This)->lpVtbl->add_IsInputRedirectedChanged(This,handler,token)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_remove_IsInputRedirectedChanged(This,token) (This)->lpVtbl->remove_IsInputRedirectedChanged(This,token)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_get_Visible(This,value) (This)->lpVtbl->get_Visible(This,value)
#define __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_get_IsInputRedirected(This,value) (This)->lpVtbl->get_IsInputRedirected(This,value)
#else
/*** IUnknown methods ***/
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_QueryInterface(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static __WIDL_INLINE ULONG __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_AddRef(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This) {
    return This->lpVtbl->AddRef(This);
}
static __WIDL_INLINE ULONG __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_Release(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This) {
    return This->lpVtbl->Release(This);
}
/*** IInspectable methods ***/
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetIids(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,ULONG *iidCount,IID **iids) {
    return This->lpVtbl->GetIids(This,iidCount,iids);
}
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetRuntimeClassName(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,HSTRING *className) {
    return This->lpVtbl->GetRuntimeClassName(This,className);
}
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetTrustLevel(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,TrustLevel *trustLevel) {
    return This->lpVtbl->GetTrustLevel(This,trustLevel);
}
/*** IGameBarStatics methods ***/
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_add_VisibilityChanged(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,__FIEventHandler_1_IInspectable *handler,EventRegistrationToken *token) {
    return This->lpVtbl->add_VisibilityChanged(This,handler,token);
}
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_remove_VisibilityChanged(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,EventRegistrationToken token) {
    return This->lpVtbl->remove_VisibilityChanged(This,token);
}
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_add_IsInputRedirectedChanged(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,__FIEventHandler_1_IInspectable *handler,EventRegistrationToken *token) {
    return This->lpVtbl->add_IsInputRedirectedChanged(This,handler,token);
}
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_remove_IsInputRedirectedChanged(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,EventRegistrationToken token) {
    return This->lpVtbl->remove_IsInputRedirectedChanged(This,token);
}
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_get_Visible(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,boolean *value) {
    return This->lpVtbl->get_Visible(This,value);
}
static __WIDL_INLINE HRESULT __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_get_IsInputRedirected(__x_ABI_CWindows_CGaming_CUI_CIGameBarStatics* This,boolean *value) {
    return This->lpVtbl->get_IsInputRedirected(This,value);
}
#endif
#ifdef WIDL_using_Windows_Gaming_UI
#define IID_IGameBarStatics IID___x_ABI_CWindows_CGaming_CUI_CIGameBarStatics
#define IGameBarStaticsVtbl __x_ABI_CWindows_CGaming_CUI_CIGameBarStaticsVtbl
#define IGameBarStatics __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics
#define IGameBarStatics_QueryInterface __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_QueryInterface
#define IGameBarStatics_AddRef __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_AddRef
#define IGameBarStatics_Release __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_Release
#define IGameBarStatics_GetIids __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetIids
#define IGameBarStatics_GetRuntimeClassName __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetRuntimeClassName
#define IGameBarStatics_GetTrustLevel __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_GetTrustLevel
#define IGameBarStatics_add_VisibilityChanged __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_add_VisibilityChanged
#define IGameBarStatics_remove_VisibilityChanged __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_remove_VisibilityChanged
#define IGameBarStatics_add_IsInputRedirectedChanged __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_add_IsInputRedirectedChanged
#define IGameBarStatics_remove_IsInputRedirectedChanged __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_remove_IsInputRedirectedChanged
#define IGameBarStatics_get_Visible __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_get_Visible
#define IGameBarStatics_get_IsInputRedirected __x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_get_IsInputRedirected
#endif /* WIDL_using_Windows_Gaming_UI */
#endif

#endif

#endif  /* ____x_ABI_CWindows_CGaming_CUI_CIGameBarStatics_INTERFACE_DEFINED__ */
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000 */

/*
 * Class Windows.Gaming.UI.GameBar
 */
#if WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000
#ifndef RUNTIMECLASS_Windows_Gaming_UI_GameBar_DEFINED
#define RUNTIMECLASS_Windows_Gaming_UI_GameBar_DEFINED
#if !defined(_MSC_VER) && !defined(__MINGW32__)
static const WCHAR RuntimeClass_Windows_Gaming_UI_GameBar[] = {'W','i','n','d','o','w','s','.','G','a','m','i','n','g','.','U','I','.','G','a','m','e','B','a','r',0};
#elif defined(__GNUC__) && !defined(__cplusplus)
const DECLSPEC_SELECTANY WCHAR RuntimeClass_Windows_Gaming_UI_GameBar[] = L"Windows.Gaming.UI.GameBar";
#else
extern const DECLSPEC_SELECTANY WCHAR RuntimeClass_Windows_Gaming_UI_GameBar[] = {'W','i','n','d','o','w','s','.','G','a','m','i','n','g','.','U','I','.','G','a','m','e','B','a','r',0};
#endif
#endif /* RUNTIMECLASS_Windows_Gaming_UI_GameBar_DEFINED */
#endif /* WINDOWS_FOUNDATION_UNIVERSALAPICONTRACT_VERSION >= 0x20000 */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __windows_gaming_ui_h__ */
