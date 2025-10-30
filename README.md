# tvrender-samples

Some small demo projects to show the functionality of TVrender

## Running tvrender-samples in a Linux terminal

### Prerequisites

- [TVrender](https://github.com/igni-project/tvrender)
- [tvrender-samples](https://github.com/igni-project/tvrender-samples), fully installed

1. Open a terminal.
2. `export TVR_DISPLAY=/run/user/$UID/tvr_display0`
3. In another terminal window, run the TVrender server with its socket address set to that of the `TVR_DISPLAY` environment variable.
    As a full command, this is: 
    `tvrender -v -d /run/user/$UID/srv`
4. Run one of the installed TVrender samples, such as `tvrender-sample-triangle`.

