package org.tvp.kirikiri2;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings.Secure;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.FrameLayout;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

//import android.os.Build.VERSION;
public class KR2Activity extends Activity {
   public static final Companion Companion = new Companion();
   private static final String TAG = "krkr2";
   private static volatile KR2Activity instance;
   private static volatile Context appContext;
   private static final Handler uiHandler = new Handler(Looper.getMainLooper());

   @Override
   protected void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);
      instance = this;
      appContext = this.getApplicationContext();
   }

   @Override
   protected void onDestroy() {
      if (instance == this) {
         instance = null;
      }
      super.onDestroy();
   }

   public static final KR2Activity GetInstance() {
      return Companion.GetInstance();
   }

   public static final void updateMemoryInfo() {
      Companion.updateMemoryInfo();
   }

   public static final long getAvailMemory() {
      return Companion.getAvailMemory();
   }

   public static final long getUsedMemory() {
      return Companion.getUsedMemory();
   }

   public static final String getDeviceId() {
      return Companion.getDeviceId();
   }

   public static final String GetVersion() {
      return Companion.GetVersion();
   }

   public static final String getLocaleName() {
      return Companion.getLocaleName();
   }

   public static final String[] getStoragePath() {
      return Companion.getStoragePath();
   }

   public static final boolean isWritableNormalOrSaf(String path) {
      return Companion.isWritableNormalOrSaf(path);
   }

   public static final boolean CreateFolders(String path) {
      return Companion.CreateFolders(path);
   }

   public static final boolean WriteFile(String path, byte[] data) {
      return Companion.WriteFile(path, data);
   }

   public static final boolean DeleteFile(String path) {
      return Companion.DeleteFile(path);
   }

   public static final boolean RenameFile(String from, String to) {
      return Companion.RenameFile(from, to);
   }

   public static final void MessageController(int adType, int arg1, int arg2) {
      Companion.MessageController(adType, arg1, arg2);
   }

   public static final void ShowMessageBox(String title, String message, String[] buttons) {
      Companion.ShowMessageBox(title, message, buttons);
   }

   public static final void ShowInputBox(String title, String prompt, String initText, String[] buttons) {
      Companion.ShowInputBox(title, prompt, initText, buttons);
   }

   public static final void hideTextInput() {
      Companion.hideTextInput();
   }

   public static final void showTextInput(int x, int y, int w, int h) {
      Companion.showTextInput(x, y, w, h);
   }

   public static final void exit() {
      Companion.exit();
   }

   private static final native void nativeOnMessageBoxResult(int var0);

   private static final native void nativeOnInputBoxResult(int var0, String var1);

   public static final class Companion {
      private Companion() {
      }

      public final KR2Activity GetInstance() {
         return KR2Activity.instance;
      }

      public final void updateMemoryInfo() {
      }

      public final long getAvailMemory() {
         if (KR2Activity.appContext == null) {
            return 0L;
         } else {
            Context ctx = KR2Activity.appContext;
            Object var3 = ctx.getSystemService("activity");
            ActivityManager am = var3 instanceof ActivityManager ? (ActivityManager)var3 : null;
            ActivityManager.MemoryInfo info = new ActivityManager.MemoryInfo();
            if (am != null) {
               am.getMemoryInfo(info);
            }
            return info.availMem;
         }
      }

      public final long getUsedMemory() {
         if (KR2Activity.appContext == null) {
            return 0L;
         } else {
            Context ctx = KR2Activity.appContext;
            Object var3 = ctx.getSystemService("activity");
            ActivityManager am = var3 instanceof ActivityManager ? (ActivityManager)var3 : null;
            ActivityManager.MemoryInfo info = new ActivityManager.MemoryInfo();
            if (am != null) {
               am.getMemoryInfo(info);
            }
            return info.totalMem - info.availMem;
         }
      }

      public final String getDeviceId() {
         if (KR2Activity.appContext == null) {
            return "";
         } else {
            Context ctx = KR2Activity.appContext;
            String var2 = Secure.getString(ctx.getContentResolver(), "android_id");
            if (var2 == null) {
               var2 = "";
            }
            return var2;
         }
      }


      public final String GetVersion() {
         if (KR2Activity.appContext == null) {
            return "";
         } else {
            Context ctx = KR2Activity.appContext;

            try {
               PackageManager pm = ctx.getPackageManager();
               String pkg = ctx.getPackageName();
               PackageInfo pi = /*VERSION.SDK_INT >= 33 ? pm.getPackageInfo(pkg, PackageInfoFlags.of(0L)) :*/ pm.getPackageInfo(pkg, 0);
               String var7 = pi.versionName;
               if (var7 == null) {
                  var7 = "";
               }
               return var7;
            } catch (Exception var5) {
               return "";
            }
         }
      }

      public final String getLocaleName() {
         //Intrinsics.checkNotNullExpressionValue(var10000, "getLanguage(...)");
         return Locale.getDefault().getLanguage();
      }

      public final String[] getStoragePath() {
         if (KR2Activity.appContext == null) {
            return new String[0];
         } else {
            Context ctx = KR2Activity.appContext;
            List<String> paths = new ArrayList<String>();
            File[] var13 = ctx.getExternalFilesDirs((String)null);
            if (var13 != null) {
               int var6 = 0;
               for(int var7 = var13.length; var6 < var7; ++var6) {
                  Object element$iv = var13[var6];
                  if (element$iv != null) {
                     //Intrinsics.checkNotNullExpressionValue(var10001, "getAbsolutePath(...)");
                     paths.add(((File)element$iv).getAbsolutePath());
                  }
               }
            }

            File internal = ctx.getFilesDir();
            if (internal != null) {
               String var14 = internal.getAbsolutePath();
               //Intrinsics.checkNotNullExpressionValue(var14, "getAbsolutePath(...)");
               paths.add(var14);
            }

            return paths.toArray(new String[0]);
         }
      }

      public final boolean isWritableNormalOrSaf(String path) {
         //Intrinsics.checkNotNullParameter(path, "path");
         try {
            File file = new File(path);
            if (!file.exists()) {
               file.mkdirs();
            }
            return file.canWrite();
         } catch (Exception var4) {
            return false;
         }
      }

      public final boolean CreateFolders(String path) {
         //Intrinsics.checkNotNullParameter(path, "path");
         try {
            return (new File(path)).mkdirs();
         } catch (Exception var4) {
            return false;
         }
      }

      public final boolean WriteFile(String path, byte[] data) {
         //Intrinsics.checkNotNullParameter(path, "path");
         //Intrinsics.checkNotNullParameter(data, "data");

         try {
            //FilesKt.writeBytes(new File(path), data);
        	 FileOutputStream it = null;
        	 try {
        		 it = new FileOutputStream(new File(path));
        		 it.write(data);
        	 } catch (IOException e) {
        		 e.printStackTrace();
        	 } finally {
        		 if (it != null) {
        			 it.close();
        		 }
        	 }
        	 return true;
         } catch (Exception var5) {
        	 return false;
         }
      }

      public final boolean DeleteFile(String path) {
         //Intrinsics.checkNotNullParameter(path, "path");
    	 try {
            return (new File(path)).delete();
         } catch (Exception var4) {
            return false;
         }
      }

      public final boolean RenameFile(String from, String to) {
         //Intrinsics.checkNotNullParameter(from, "from");
         //Intrinsics.checkNotNullParameter(to, "to");
         try {
            return (new File(from)).renameTo(new File(to));
         } catch (Exception var5) {
            return false;
         }
      }

      public final void MessageController(int adType, int arg1, int arg2) {
         Log.d("krkr2", "MessageController ignored: " + adType + ' ' + arg1 + ' ' + arg2);
      }

      public final void ShowMessageBox(final String title, final String message, final String[] buttons) {
//         Intrinsics.checkNotNullParameter(title, "title");
//         Intrinsics.checkNotNullParameter(message, "message");
//         Intrinsics.checkNotNullParameter(buttons, "buttons");
         KR2Activity var10000 = KR2Activity.instance;
         if (var10000 == null) {
            Log.w("krkr2", "ShowMessageBox: no activity, auto-confirming");
            this.nativeOnMessageBoxResult(0);
         } else {
            final KR2Activity ctx = var10000;
            KR2Activity.uiHandler.post(new Runnable() {
				@Override
				public void run() {
			         try {
			             AlertDialog.Builder var10000 = (new AlertDialog.Builder((Context)ctx)).setTitle((CharSequence)title).setMessage((CharSequence)message).setCancelable(false);
			             //Intrinsics.checkNotNullExpressionValue(var10000, "setCancelable(...)");
			             AlertDialog.Builder builder = var10000;
			             if (buttons.length != 0) {
			                builder.setPositiveButton((CharSequence)buttons[0], new DialogInterface.OnClickListener() {
								@Override
								public void onClick(DialogInterface arg0, int arg1) {
									KR2Activity.Companion.nativeOnMessageBoxResult(0);
								}
							});
			             }
			             if (buttons.length >= 2) {
			                builder.setNeutralButton((CharSequence)buttons[1], new DialogInterface.OnClickListener() {
								@Override
								public void onClick(DialogInterface arg0, int arg1) {
									KR2Activity.Companion.nativeOnMessageBoxResult(1);
								}
							});
			             }
			             if (buttons.length >= 3) {
			                builder.setNegativeButton((CharSequence)buttons[2], new DialogInterface.OnClickListener() {
								@Override
								public void onClick(DialogInterface arg0, int arg1) {
									KR2Activity.Companion.nativeOnMessageBoxResult(2);
								}
							});
			             }
			             builder.show();
			          } catch (Exception e) {
			             Log.e("krkr2", "ShowMessageBox failed", (Throwable)e);
			             KR2Activity.Companion.nativeOnMessageBoxResult(0);
			          }
				}
            });
         }
      }

      public final void ShowInputBox(final String title, final String prompt, final String initText, final String[] buttons) {
//         Intrinsics.checkNotNullParameter(title, "title");
//         Intrinsics.checkNotNullParameter(prompt, "prompt");
//         Intrinsics.checkNotNullParameter(initText, "initText");
//         Intrinsics.checkNotNullParameter(buttons, "buttons");
         if (KR2Activity.instance == null) {
            Log.w("krkr2", "ShowInputBox: no activity, auto-confirming");
            this.nativeOnInputBoxResult(0, initText);
         } else {
            final KR2Activity ctx = KR2Activity.instance;
            KR2Activity.uiHandler.post(new Runnable() {
				@Override
				public void run() {
			         try {
			             int dp24 = (int)((float)24 * ctx.getResources().getDisplayMetrics().density);
			             FrameLayout container = new FrameLayout((Context)ctx);
			             container.setPadding(dp24, 0, dp24, 0);
			             final EditText editText = new EditText((Context)ctx);
			             editText.setText((CharSequence)initText);
			             container.addView((View)editText, (ViewGroup.LayoutParams)(new FrameLayout.LayoutParams(-1, -2)));
			             AlertDialog.Builder builder = new AlertDialog.Builder((Context)ctx)
			            		 .setTitle((CharSequence)title)
			            		 .setMessage((CharSequence)prompt)
			            		 .setView((View)container)
			            		 .setCancelable(false);
			             //Intrinsics.checkNotNullExpressionValue(var10000, "setCancelable(...)");
			             if (buttons.length != 0) {
			                builder.setPositiveButton((CharSequence)buttons[0], new DialogInterface.OnClickListener() {
			                    @Override
			                    public void onClick(DialogInterface dialog, int which) {
			                    	KR2Activity.Companion.nativeOnInputBoxResult(0, editText.getText().toString());
			                    }
			                });
			             }

			             if (buttons.length >= 2) {
			                builder.setNeutralButton((CharSequence)buttons[1], new DialogInterface.OnClickListener() {
			                    @Override
			                    public void onClick(DialogInterface dialog, int which) {
			                    	KR2Activity.Companion.nativeOnInputBoxResult(1, editText.getText().toString());
			                    }
			                });
			             }

			             if (buttons.length >= 3) {
			                builder.setNegativeButton((CharSequence)buttons[2], new DialogInterface.OnClickListener() {
			                    @Override
			                    public void onClick(DialogInterface dialog, int which) {
			                    	KR2Activity.Companion.nativeOnInputBoxResult(2, editText.getText().toString());
			                    }
			                });
			             }

			             builder.show();
			             editText.requestFocus();
			          } catch (Exception e) {
			             Log.e("krkr2", "ShowInputBox failed", (Throwable)e);
			             KR2Activity.Companion.nativeOnInputBoxResult(0, initText);
			          }
				}
            });
         }
      }

      public final void hideTextInput() {
      }

      public final void showTextInput(int x, int y, int w, int h) {
      }

      public final void exit() {
         if (KR2Activity.instance != null) {
        	 KR2Activity.instance.finish();
         }
      }

      private final void nativeOnMessageBoxResult(int result) {
         KR2Activity.nativeOnMessageBoxResult(result);
      }

      private final void nativeOnInputBoxResult(int result, String text) {
         KR2Activity.nativeOnInputBoxResult(result, text);
      }
   }
}
