LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= uchardet

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src

LOCAL_CFLAGS += 

LOCAL_SRC_FILES := \
src/CharDistribution.cpp \
src/JpCntx.cpp \
src/LangModels/LangArabicModel.cpp \
src/LangModels/LangBulgarianModel.cpp \
src/LangModels/LangCroatianModel.cpp \
src/LangModels/LangCzechModel.cpp \
src/LangModels/LangEsperantoModel.cpp \
src/LangModels/LangEstonianModel.cpp \
src/LangModels/LangFinnishModel.cpp \
src/LangModels/LangFrenchModel.cpp \
src/LangModels/LangDanishModel.cpp \
src/LangModels/LangGermanModel.cpp \
src/LangModels/LangGreekModel.cpp \
src/LangModels/LangHungarianModel.cpp \
src/LangModels/LangHebrewModel.cpp \
src/LangModels/LangIrishModel.cpp \
src/LangModels/LangItalianModel.cpp \
src/LangModels/LangLithuanianModel.cpp \
src/LangModels/LangLatvianModel.cpp \
src/LangModels/LangMalteseModel.cpp \
src/LangModels/LangPolishModel.cpp \
src/LangModels/LangPortugueseModel.cpp \
src/LangModels/LangRomanianModel.cpp \
src/LangModels/LangRussianModel.cpp \
src/LangModels/LangSlovakModel.cpp \
src/LangModels/LangSloveneModel.cpp \
src/LangModels/LangSwedishModel.cpp \
src/LangModels/LangSpanishModel.cpp \
src/LangModels/LangThaiModel.cpp \
src/LangModels/LangTurkishModel.cpp \
src/LangModels/LangVietnameseModel.cpp \
src/LangModels/LangNorwegianModel.cpp \
src/nsHebrewProber.cpp \
src/nsCharSetProber.cpp \
src/nsBig5Prober.cpp \
src/nsEUCJPProber.cpp \
src/nsEUCKRProber.cpp \
src/nsEUCTWProber.cpp \
src/nsEscCharsetProber.cpp \
src/nsEscSM.cpp \
src/nsGB2312Prober.cpp \
src/nsMBCSGroupProber.cpp \
src/nsMBCSSM.cpp \
src/nsSBCSGroupProber.cpp \
src/nsSBCharSetProber.cpp \
src/nsSJISProber.cpp \
src/nsUTF8Prober.cpp \
src/nsLatin1Prober.cpp \
src/nsUniversalDetector.cpp \
src/uchardet.cpp

include $(BUILD_STATIC_LIBRARY)
