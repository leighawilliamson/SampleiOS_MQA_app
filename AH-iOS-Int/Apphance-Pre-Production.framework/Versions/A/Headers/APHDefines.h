//  Copyright 2013 uTest. All rights reserved.

#ifdef __cplusplus
#define APH_EXTERN		extern "C" __attribute__((visibility ("default")))
#else
#define APH_EXTERN	        extern __attribute__((visibility ("default")))
#endif

/** DEPRECATED!!! Use APHSettings instead! **/

/** Possible values of Apphance modes. **/

/*
 * This is the market mode. Apphance will run with a minimal amount of enabled options,
 * in order to minimize impact on performance. Not yet implemented.
 */

APH_EXTERN NSString* const kAPHApphanceModeMarket;

/*
 * This mode represents the 'silent' version of Apphance. That means the
 * user (or tester) won't see any Apphance-related UI. You can use this,
 * for instance, if you wish to hide the fact you've embedded Apphance from
 * testers. All crashes and logs will be sent to the server.
 */

APH_EXTERN NSString* const kAPHApphanceModeSilent;

/*
 * This is the designated mode. Apphance will run with standard settings.
 */

APH_EXTERN NSString* const kAPHApphanceModeQA;
