function varargout = button_group_demo(varargin)
% BUTTON_GROUP_DEMO MATLAB code for button_group_demo.fig
%      BUTTON_GROUP_DEMO, by itself, creates a new BUTTON_GROUP_DEMO or raises the existing
%      singleton*.
%
%      H = BUTTON_GROUP_DEMO returns the handle to a new BUTTON_GROUP_DEMO or the handle to
%      the existing singleton*.
%
%      BUTTON_GROUP_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BUTTON_GROUP_DEMO.M with the given input arguments.
%
%      BUTTON_GROUP_DEMO('Property','Value',...) creates a new BUTTON_GROUP_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before button_group_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to button_group_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help button_group_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 14:01:50

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @button_group_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @button_group_demo_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before button_group_demo is made visible.
function button_group_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to button_group_demo (see VARARGIN)

% Choose default command line output for button_group_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes button_group_demo wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = button_group_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function num_Callback(hObject, eventdata, handles)
% hObject    handle to num (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num as text
%        str2double(get(hObject,'String')) returns contents of num as a double


% --- Executes during object creation, after setting all properties.
function num_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes when selected object is changed in bin_dec.
function bin_dec_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in bin_dec 
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)
str = get(handles.num, 'String');
switch get(hObject, 'Tag')
    case 'bin'
        val = floor(str2double(str));
        if (~isnan(val)) && (val >= 0)
            set(handles.num, 'String', dec2bin(val))
        else
            set(handles.num, 'String', 'ÊäÈë´íÎó')
        end
    case 'dec'
        if all(str == '0' | str == '1')
            set(handles.num, 'String', num2str(bin2dec(str)))
        else
            set(handles.num, 'String', 'ÊäÈë´íÎó')
        end
end
