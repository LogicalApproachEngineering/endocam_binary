REV: 1.00(LAE) - 2023-02-16 <br>
    - Provides working sliders in setting-screen <br>
    - Camera presets can be saved and retrieved <br>
    - Repurpose zoom button to start/stop camera pipeline <br>

REV: 1.01(LAE) - 2023-02-22 <br>
    - Allow LED slider to go up to 300mA with even step size of 5mA <br>
    - Utilize new Gstreamer sink to get around overlay issue and improve latency <br>
    - Update slider CSS to eliminate slider's trough <br>

REV: 1.02(LAE) - 2023-03-16 <br>
    - Fix error which LED sliders does not sync on live-screen and settings-screen <br>
    - Remove Zoom button <br>
    - At the end of recorded video, the video stops at the last frame <br>
    - Make last slider "gain AGC" in settings screen <br>
    - New LED slider stepsize 0-100=1 100-250=5 250-300=10 <br>
    - New slider reset values <br>
    - Added independent I2S test <br>

REV: 1.03(LAE) - 2023-03-23 <br>
    - Fix bugs in review-screen when trash button clicked <br>
    - Add long/short press function for pin 31. Long press will start/stop video. Short press will capture current image <br>
    - Restore Zoom button (was repurposed to start/stop the video live stream) <br>
    - Added I2S to main code. Plays shutter sound when capturing image. (Known 'pop' heard on LAE speaker. Solution TBD) <br>

REV: 1.04(LAE) - 2023-03-23 <br>
    - Change last slider back to GAMMA <br>

REV: 1.05(LAE) - 2023-04-11 <br>
    - Updated Logo on Live Stream Screen and Settings Screen <br>
    - Updated Labels on Settings Screen <br>
    
REV: 1.06(LAE) - 2023-04-13 <br>
    - Added probe hot swap (Does not work when recording a video. Does not show "Connect Probe" when disconnected. Video slightly miss aligned) <br>
   
REV: 1.07(LAE) - 2023-04-17 <br>
    - Added white bar on camera stream to indicate probe orientation <br> 

REV: 1.08(LAE) - 2023-04-19 <br>
    - Removed from Secret Settings menu: Cable length, Noise Reduction, PIC, FPGA. <br>
    - Removed Zoom button from Live View. <br>
    - Increased the date-time font size. <br>
    - (A) Added circle and square masks. <br>
    - (B) Temporarily repurposed the Export button to exit to Desktop. <br>

REV: 1.09(LAE) - 2023-04-25 <br>
    - Implemented dual pipeline for reliable probe hot swap. <br>
    - Probe connect graphic shows when probe is disconnected. <br>
    - Updated square and circle masks <br>

REV: 1.10(LAE) - 2023-04-27 <br>
    - Implemented I2C for controlling front panel LEDs. <br>
    - Allowed probe detect to work all screens. It won't work well when probe is not connected initially. Will investigate more <br>

REV: 1.11(LAE) - 2023-05-01 <br>
    - Refined probe detect function. <br>

REV: 1.12(LAE) - 2023-05-04 <br>
    - Power button LEDs change color when connecting and disconnecting a probe.<br>

REV: 1.13(LAE) - 2023-05-18 <br>
    - Import/Export functionality working. <br>
    - Added independent Exit/Desktop Button. <br>

REV: 1.14(LAE) - 2023-06-05 <br>
    - New Square Mask graphic <br>

REV: 1.15(LAE) - 2023-06-22 <br>
    - No cursor on start up <br>
    - Cursor can be toggled on and off in secret settings. <br>

REV: 1.16(LAE) - 2023-06-29 <br>
    - Device no longer goes to sleep after ~10mins. <br>

REV: 1.17(LAE) - 2023-07-03 <br>
    - Cursor becomes visible when exiting to desktop. <br>
    - Fixed "blank" UI when inserting a USB drive. <br>

REV: 1.18(LAE) - 2023-09-07 <br>
    - Fixed dark image issue when re-connecting a probe. <br>

REV: 1.19(LAE) - 2023-10-19 <br>
    - Presets load/save depending on probe type <br>

REV: 1.20(LAE) - 2023-10-24 <br>
    - Preset reset clears all probe presets. <br>

REV: 1.21(LAE) - 2023-10-30 <br>
    - Button LEDs working. <br>

REV: 1.22(LAE) - 2023-10-31 <br>
    - When probe is connected, the "probe connecting" screen shows. <br>

REV: 1.23(LAE) - 2023-11-07 <br>
    - Hid the blue square that shows when probe is connecting. <br>
    - Fixed live view resizing when switching between user settings and secret settings. <br>

REV: 1.24(LAE) - 2023-11-14 <br>
    - Fix issue in Secret Settings Screen where live view would disappear after using the keyboard (bug list 23). <br>

REV: 1.25(LAE) - 2023-11-21 <br>
    - Probe LED automatically is set to 40% on start-up and reconnection. <br>

REV: 1.26(LAE) - 2023-11-29 <br>
    - On screen keyboard now has transparent background.  <br>
    - LED slider adjusts to 40% when a probe is connected. <br>
    - Presets get loaded per correct type of probe, however UI does not update until closing and opening settings. <br>

Rev: 1.27(LAE) - 2023-12-04 <br>
    - Start up time significantly improved/less jerky. <br>
    - Preset UI gets updated when the scope is plugged in. <br>

Rev 1.28(LAE) - 2023-12-12 <br>
    - Removed all old system code/resources not being used. <br>
    - Probe LED slider is working, sets to 40% on probe connection. <br>
    - Build warnings are fixed. <br>


