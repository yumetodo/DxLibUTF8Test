#include <DxLib.h>
int WINAPI WinMain(HINSTANCE , HINSTANCE , LPSTR , int)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1){
		return -1;
	}
	const auto font_handle_yu_goshic = CreateFontToHandle("游ゴシック", -1, -1, DX_FONTTYPE_ANTIALIASING);
	const auto font_handle_segoe_ui_emoji = CreateFontToHandle("Segoe UI Emoji", -1, -1, DX_FONTTYPE_ANTIALIASING);
	AddSubstitutionFontToHandle(font_handle_yu_goshic, font_handle_segoe_ui_emoji, 0, 0);
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
#if defined(__cpp_char8_t) && 201803 <= __cpp_char8_t
	DrawStringToHandle(10, 10, reinterpret_cast<const char*>(u8"aあ🍣🍺"), GetColor(0xFF, 0xFF, 0xFF), font_handle_yu_goshic);
#else
	DrawStringToHandle(10, 10, u8"aあ🍣🍺", GetColor(0xFF, 0xFF, 0xFF), font_handle_yu_goshic);
#endif
	WaitKey();
	DxLib_End();
	return 0;
}