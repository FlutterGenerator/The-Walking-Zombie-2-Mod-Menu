#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "And64InlineHook/And64InlineHook.hpp"
#include "Menu/Setup.h"

//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

struct My_Patches {

MemoryPatch Coins, Silver, Gas, Perks, Skills, AutoHeal, Immortal , Karma, Speed, Damage, Ammo, Spread1, Spread2, Shake1, Shake2, Shake3, Reload, Recoil1, Recoil2, Range, Ads ,AntiDetect, Anticheat1, Anticheat2, Anticheat3, Anticheat4, Anticheat5, Anticheat6, Anticheat7, Anticheat8, Anticheat9, Anticheat10, Antiban1, Antiban2,  Antiban3, Antiban4, Antiban5, Antiban6;

} hexPatches;
bool cheat;
bool Gold = false;

int(*_Gold)(void *player);
int GoldX(void *player) {
    if(player != NULL) {
        if(Gold) {
            return 696969696;
        }
    }
    return _Gold(player);
}
// we will run our hacks in a new thread so our while loop doesn't block process main thread
void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));

    //Anti-lib rename
    /*
    do {
        sleep(1);
    } while (!isLibraryLoaded("libYOURNAME.so"));*/

    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);

#if defined(__aarch64__) //To compile this code for arm64 lib only. Do not worry about greyed out highlighting code, it still works

#else 

HOOK_LIB("libil2cpp.so", "0x2FE0FE8", GoldX, _Gold); // public int get_CoinsGold() { }

//hexPatches.Coins = MemoryPatch::createWithHex("libil2cpp.so",0x2FE0FE8,"FF 09 0C E3 00 10 A0 E3 9A 0B 43 E3 1E FF 2F E1"); // public int get_CoinsGold() { }
hexPatches.Silver = MemoryPatch::createWithHex("libil2cpp.so",0x2FE0E6C,"FF 09 0C E3 00 10 A0 E3 9A 0B 43 E3 1E FF 2F E1"); // public int get_CoinsSilver() { }
hexPatches.Gas = MemoryPatch::createWithHex("libil2cpp.so",0x2FDFDA8,"1C0644E31EFF2FE1"); // public float get_Gas() { }
hexPatches.Perks = MemoryPatch::createWithHex("libil2cpp.so",0x30FCC38,"3F0204E30010A0E30F0040E31EFF2FE1"); // public int get_FreePerksPoints() { }
hexPatches.Skills = MemoryPatch::createWithHex("libil2cpp.so",0x30FE254,"3F0204E30010A0E30F0040E31EFF2FE1"); // public int get_FreeSkillsPoints() { }
hexPatches.AutoHeal = MemoryPatch::createWithHex("libil2cpp.so",0x2FDDAC8,"1C0644E31EFF2FE1"); // public float GetHeal(float pOriginalHeal) { }
hexPatches.Immortal = MemoryPatch::createWithHex("libil2cpp.so",0x2FF412C,"0000A0E31EFF2FE1"); // public static int GetDamageAgainsPlayer(float pDamageInitial, int pEnemyLevel, int pPlayerLevel) { }
hexPatches.Karma = MemoryPatch::createWithHex("libil2cpp.so",0x2FE1E90,"3F0204E30010A0E30F0040E31EFF2FE1"); // public int get_Karma() { }
hexPatches.Speed = MemoryPatch::createWithHex("libil2cpp.so",0x2FE33E4,"A00044E31EFF2EE1"); // public float get_MovementMultiplier() { }
hexPatches.Damage = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD5CC,"3F0204E31EFF2FE1"); // public int GetDamage() { }
hexPatches.Ammo = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD950,"0100A0E31EFF2FE1"); // public bool get_IsInfinityAmmoStock() { }
hexPatches.Spread1 = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD55C,"0000A0E31EFF2FE1"); // public float get_MinimumSpread() { }
hexPatches.Spread2 = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD564,"0000A0E31EFF2FE1"); // public float get_MaximumSpread() { }
hexPatches.Shake1 = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD5AC,"0000A0E31EFF2FE1"); // public float get_ShakeSpeed() { }
hexPatches.Shake2 = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD5B4,"0000A0E31EFF2FE1"); // public float get_ShakeDuration() { }
hexPatches.Shake3 = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD5BC,"0000A0E31EFF2FE1"); // public float get_ShakeMagnitude() { }
hexPatches.Reload = MemoryPatch::createWithHex("libil2cpp.so",0x2FCDDB0,"0000A0E31EFF2FE1"); // public float get_ReloadTime() { }
hexPatches.Recoil1 = MemoryPatch::createWithHex("libil2cpp.so",0x2FCDDC0,"0000A0E31EFF2FE1"); // public float get_RecoilDuration() { }
hexPatches.Recoil2 = MemoryPatch::createWithHex("libil2cpp.so",0x2FCDDC8,"0000A0E31EFF2FE1"); // public float get_RecoilMagnitude() { }
hexPatches.Range = MemoryPatch::createWithHex("libil2cpp.so",0x2FCD514,"0000A0E31EFF2FE1"); // public float get_WeaponRange() { }
hexPatches.Ads = MemoryPatch::createWithHex("libil2cpp.so",0x2FE1678,"0000A0E31EFF2FE1"); // public bool get_AdsEnabled() { }

//AntiDetect
hexPatches.AntiDetect = MemoryPatch::createWithHex("libil2cpp.so",0x1393298,"0000A0E31EFF2FE1"); // public void add_CheatDetected(Action value) { }

//AntiCheat
hexPatches.Anticheat1 = MemoryPatch::createWithHex("libil2cpp.so",0x1393298,"1E FF 2F E1"); // public void add_CheatDetected(Action value) { }
hexPatches.Anticheat2 = MemoryPatch::createWithHex("libil2cpp.so",0x13933F8,"1E FF 2F E1"); // public bool get_IsRunning() { }
hexPatches.Anticheat3 = MemoryPatch::createWithHex("libil2cpp.so",0x13934EC,"1E FF 2F E1"); // internal virtual void OnCheatingDetected() { }
//hexPatches.Anticheat4 = MemoryPatch::createWithHex("libil2cpp.so",0xFFD554,"1E FF 2F E1");
//hexPatches.Anticheat5 = MemoryPatch::createWithHex("libil2cpp.so",0xFFD5F0,"1E FF 2F E1");
//hexPatches.Anticheat6 = MemoryPatch::createWithHex("libil2cpp.so",0xFFD70C,"1E FF 2F E1");
//hexPatches.Anticheat7 = MemoryPatch::createWithHex("libil2cpp.so",0xFFD79C,"1E FF 2F E1");
//hexPatches.Anticheat8 = MemoryPatch::createWithHex("libil2cpp.so",0xFFD838,"1E FF 2F E1");
//hexPatches.Anticheat9 = MemoryPatch::createWithHex("libil2cpp.so",0xFFD8EC,"1E FF 2F E1");
//hexPatches.Anticheat10 = MemoryPatch::createWithHex("libil2cpp.so",0xFFD988,"1E FF 2F E1");

//AntiBan
hexPatches.Antiban1 = MemoryPatch::createWithHex("libil2cpp.so",0x32DEE24,"0000A0E31EFF2FE1"); // private bool get_IsOutOfBoundaries() { }
hexPatches.Antiban2 = MemoryPatch::createWithHex("libil2cpp.so",0x32DEE50,"0000A0E31EFF2FE1"); // public bool GetCheckEnabled() { }
hexPatches.Antiban3 = MemoryPatch::createWithHex("libil2cpp.so",0x32DF128,"0000A0E31EFF2FE1"); // public void FrozenValueDetected() { }
hexPatches.Antiban4 = MemoryPatch::createWithHex("libil2cpp.so",0x32DF3DC,"0000A0E31EFF2FE1"); // public void TryCheckCoinBoundaries() { }
//hexPatches.Antiban5 = MemoryPatch::createWithHex("libil2cpp.so",0xA00390,"0000A0E31EFF2FE1");
hexPatches.Antiban6 = MemoryPatch::createWithHex("libil2cpp.so",0x32DF560,"1E FF 2F E1"); // private void SpeedHackDetected() { }

    LOGI(OBFUSCATE("Done"));
#endif

    //Anti-leech
    /*if (!iconValid || !initValid || !settingsValid) {
        //Bad function to make it crash
        sleep(5);
        int *p = 0;
        *p = 0;
    }*/

    return NULL;
}

// Do not change or translate the first text unless you know what you are doing
// Assigning feature numbers is optional. Without it, it will automatically count for you, starting from 0
// Assigned feature numbers can be like any numbers 1,3,200,10... instead in order 0,1,2,3,4,5...
// ButtonLink, Category, RichTextView and RichWebView is not counted. They can't have feature number assigned
// Toggle, ButtonOnOff and Checkbox can be switched on by default, if you add True_. Example: CheckBox_True_The Check Box
// To learn HTML, go to this page: https://www.w3schools.com/

jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("Category_FEATURES"),
            OBFUSCATE("Collapse_Money And Gas"),//Not Counted
            OBFUSCATE("119_CollapseAdd_Toggle_Unlimited Coins"), //case0
            OBFUSCATE("CollapseAdd_Toggle_Unlimited Silvers"),//case1
			OBFUSCATE("CollapseAdd_Toggle_Unlimited Gas"), //case2
			OBFUSCATE("Collapse_Player Menu"),
            OBFUSCATE("CollapseAdd_Toggle_Unlimited Perks"), //case3
			OBFUSCATE("CollapseAdd_Toggle_Unlimited Skills"), //case4
            OBFUSCATE("CollapseAdd_Toggle_AutoHeall"), //case5
			OBFUSCATE("CollapseAdd_Toggle_Immortal (God mode)"), //case6
			OBFUSCATE("101_CollapseAdd_Toggle_Unlimited Karma"),
			OBFUSCATE("102_CollapseAdd_Toggle_Player Speed"),
            OBFUSCATE("CollapseAdd_Toggle_High Damage"), //case7
			OBFUSCATE("Collapse_Wepon Menu"), //not counted
			OBFUSCATE("CollapseAdd_Toggle_Unlimited Ammo"), //case8
            OBFUSCATE("CollapseAdd_Toggle_Gun No Spread"), //case9
			OBFUSCATE("CollapseAdd_Toggle_Gun No Shake"), //case10
            OBFUSCATE("CollapseAdd_Toggle_No Reload"), //case11
			OBFUSCATE("CollapseAdd_Toggle_No Recoil"), //case12
            OBFUSCATE("CollapseAdd_Toggle_Increase Bullet Range"), //case13
			OBFUSCATE("Collapse_Ads Menu"),
			OBFUSCATE("CollapseAdd_Toggle_True_Disable Ads"), //case14
			
			OBFUSCATE("Collapse_AntiCheat/AntiBan"), //not counted
			OBFUSCATE("105_CollapseAdd_Toggle_Bypass Cheat Detected(Turn when u got banner Cheats Detected)"), 
            OBFUSCATE("103_CollapseAdd_Toggle_True_Bypass AntiCheat"),
			OBFUSCATE("104_CollapseAdd_Toggle_True_Bypass AntiBan"),
    };

    //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

void Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");

    //BE CAREFUL NOT TO ACCIDENTLY REMOVE break;

    switch (featNum) {
        case 119:
            Gold = boolean;
            break;
       /* case 0:
            cheat = boolean;
            if (cheat) {
                hexPatches.Coins.Modify();
            } else {
                hexPatches.Coins.Restore();
            }
      */    break;
			case 1:
            cheat = boolean;
            if (cheat) {
                hexPatches.Silver.Modify();
            } else {
                hexPatches.Silver.Restore();
            }
            break;
			case 2:
            cheat = boolean;
            if (cheat) {
                hexPatches.Gas.Modify();
            } else {
                hexPatches.Gas.Restore();
            }
            break;
			case 3:
            cheat = boolean;
            if (cheat) {
                hexPatches.Perks.Modify();
            } else {
                hexPatches.Perks.Restore();
            }
            break;
			case 4:
            cheat = boolean;
            if (cheat) {
                hexPatches.Skills.Modify();
            } else {
                hexPatches.Skills.Restore();
            }
            break;
			case 5:
            cheat = boolean;
            if (cheat) {
                hexPatches.AutoHeal.Modify();
            } else {
                hexPatches.AutoHeal.Restore();
            }
            break;
			case 6:
            cheat = boolean;
            if (cheat) {
                hexPatches.Immortal.Modify();
            } else {
                hexPatches.Immortal.Restore();
            }
            break;
			case 101:
            cheat = boolean;
            if (cheat) {
                hexPatches.Karma.Modify();
            } else {
                hexPatches.Karma.Restore();
            }
            break;
			case 102:
            cheat = boolean;
            if (cheat) {
                hexPatches.Speed.Modify();
            } else {
                hexPatches.Speed.Restore();
            }
            break;
			case 7:
            cheat = boolean;
            if (cheat) {
                hexPatches.Damage.Modify();
            } else {
                hexPatches.Damage.Restore();
            }
            break;
			case 8:
            cheat = boolean;
            if (cheat) {
                hexPatches.Ammo.Modify();
            } else {
                hexPatches.Ammo.Restore();
            }
            break;
			case 9:
            cheat = boolean;
            if (cheat) {
                hexPatches.Spread1.Modify();
				hexPatches.Spread2.Modify();
            } else {
                hexPatches.Spread1.Restore();
				hexPatches.Spread2.Restore();
            }
            break;
			case 10:
            cheat = boolean;
            if (cheat) {
                hexPatches.Shake1.Modify();
				hexPatches.Shake2.Modify();
				hexPatches.Shake3.Modify();
            } else {
                hexPatches.Shake1.Restore();
				hexPatches.Shake2.Restore();
				hexPatches.Shake3.Restore();
            }
            break;
			case 11:
            cheat = boolean;
            if (cheat) {
                hexPatches.Reload.Modify();
            } else {
                hexPatches.Reload.Restore();			
            }
            break;
			case 12:
            cheat = boolean;
            if (cheat) {
                hexPatches.Recoil1.Modify();
				hexPatches.Recoil2.Modify();
            } else {
                hexPatches.Recoil1.Restore();
				hexPatches.Recoil2.Restore();
            }
            break;
			case 13:
            cheat = boolean;
            if (cheat) {
                hexPatches.Range.Modify();
            } else {
                hexPatches.Range.Restore();
            }
            break;
			case 14:
            cheat = boolean;
            if (cheat) {
                hexPatches.Ads.Modify();
            } else {
                hexPatches.Ads.Restore();
            }
            break;
			case 105:
            cheat = boolean;
            if (cheat) {
                hexPatches.AntiDetect.Modify();
            } else {
                hexPatches.AntiDetect.Restore();
            }
            break;
			case 103:
            cheat = boolean;
            if (cheat) {
                hexPatches.Anticheat1.Modify();
				hexPatches.Anticheat2.Modify();
				hexPatches.Anticheat3.Modify();
            } else {
                hexPatches.Anticheat1.Restore();
				hexPatches.Anticheat2.Restore();
				hexPatches.Anticheat3.Restore();
            }
            break;
			case 104:
            cheat = boolean;
            if (cheat) {
                hexPatches.Antiban1.Modify();
				hexPatches.Antiban2.Modify();
				hexPatches.Antiban3.Modify();
				hexPatches.Antiban4.Modify();
				hexPatches.Antiban6.Modify();				
            } else {
                hexPatches.Antiban1.Restore();
				hexPatches.Antiban2.Restore();
				hexPatches.Antiban3.Restore();
				hexPatches.Antiban4.Restore();
				hexPatches.Antiban6.Restore();			
            }
            break;
    }
}

__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

int RegisterMenu(JNIEnv *env) {
    JNINativeMethod methods[] = {
            {OBFUSCATE("Icon"), OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(Icon)},
            {OBFUSCATE("IconWebViewData"),  OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(IconWebViewData)},
            {OBFUSCATE("IsGameLibLoaded"),  OBFUSCATE("()Z"), reinterpret_cast<void *>(isGameLibLoaded)},
            {OBFUSCATE("Init"),  OBFUSCATE("(Landroid/content/Context;Landroid/widget/TextView;Landroid/widget/TextView;)V"), reinterpret_cast<void *>(Init)},
            {OBFUSCATE("SettingsList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(SettingsList)},
            {OBFUSCATE("GetFeatureList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(GetFeatureList)},
    };

    jclass clazz = env->FindClass(OBFUSCATE("com/android/support/Menu"));
    if (!clazz)
        return JNI_ERR;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return JNI_ERR;
    return JNI_OK;
}

int RegisterPreferences(JNIEnv *env) {
    JNINativeMethod methods[] = {
            {OBFUSCATE("Changes"), OBFUSCATE("(Landroid/content/Context;ILjava/lang/String;IZLjava/lang/String;)V"), reinterpret_cast<void *>(Changes)},
    };
    jclass clazz = env->FindClass(OBFUSCATE("com/android/support/Preferences"));
    if (!clazz)
        return JNI_ERR;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return JNI_ERR;
    return JNI_OK;
}

int RegisterMain(JNIEnv *env) {
    JNINativeMethod methods[] = {
            {OBFUSCATE("CheckOverlayPermission"), OBFUSCATE("(Landroid/content/Context;)V"), reinterpret_cast<void *>(CheckOverlayPermission)},
    };
    jclass clazz = env->FindClass(OBFUSCATE("com/android/support/Main"));
    if (!clazz)
        return JNI_ERR;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return JNI_ERR;

    return JNI_OK;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (RegisterMenu(env) != 0)
        return JNI_ERR;
    if (RegisterPreferences(env) != 0)
        return JNI_ERR;
    if (RegisterMain(env) != 0)
        return JNI_ERR;
    return JNI_VERSION_1_6;
}
