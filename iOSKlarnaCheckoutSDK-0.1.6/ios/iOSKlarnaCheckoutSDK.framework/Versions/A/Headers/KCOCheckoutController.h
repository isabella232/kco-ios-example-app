//
//  KCOCheckoutController.h
//  Pods
//
//  Created by Johan Rydenstam on 08/12/15.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol KCOCheckoutControllerDelegate <NSObject>

- (void)focusOnFieldWithRect:(CGRect)rect;
- (void)resizeCheckoutWithHeight:(CGFloat)height;

@end

/**
 * This is the controller for the checkout.
 * If the checkout will be rendered by inserting a snippet, it's highly recommended to make use of
 * KCOCheckoutViewController.
 */
@protocol KCOWebViewProxyProvider;
@protocol KCOWebViewProxyProtocol;
@interface KCOCheckoutController : NSObject

@property (nonatomic, weak) id<KCOCheckoutControllerDelegate> delegate;
@property (nonatomic, readonly) id<KCOWebViewProxyProtocol> checkoutWebViewProxy;


/**
 * Returns a controller instance. It will handle checkout events and logic require by Klarna Checkout,
 * but It will never steal the delegate from the webView.
 * This controller will keep a weak reference to the viewcontroller.
 * Accepts both WKWebView and UIWebView instances.
 */
- (instancetype)initWithViewController:(UIViewController *)viewController webView:(id)webView;

/**
 * This method NEEDS to be called when the provided viewController view is loaded
 */
- (void)notifyViewDidLoad;
- (void)setSnippet:(NSString *)snippet;
- (void)loadSnippet;

@end
