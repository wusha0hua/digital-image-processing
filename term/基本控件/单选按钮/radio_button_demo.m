function varargout = radio_button_demo(varargin)
% RADIO_BUTTON_DEMO MATLAB code for radio_button_demo.fig
%      RADIO_BUTTON_DEMO, by itself, creates a new RADIO_BUTTON_DEMO or raises the existing
%      singleton*.
%
%      H = RADIO_BUTTON_DEMO returns the handle to a new RADIO_BUTTON_DEMO or the handle to
%      the existing singleton*.
%
%      RADIO_BUTTON_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in RADIO_BUTTON_DEMO.M with the given input arguments.
%
%      RADIO_BUTTON_DEMO('Property','Value',...) creates a new RADIO_BUTTON_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before radio_button_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to radio_button_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help radio_button_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 09:01:37

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @radio_button_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @radio_button_demo_OutputFcn, ...
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


% --- Executes just before radio_button_demo is made visible.
function radio_button_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to radio_button_demo (see VARARGIN)

% Choose default command line output for radio_button_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes radio_button_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = radio_button_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on slider movement.
function my_slider_Callback(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
value = get(hObject, 'Value');
set(handles.my_static_text, 'String', sprintf('%3.0f', value));


% --- Executes during object creation, after setting all properties.
function my_slider_CreateFcn(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in save_data.
function save_data_Callback(hObject, eventdata, handles)
% hObject    handle to save_data (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of save_data
if get(hObject,'Value')
    [FileName, PathName, FilterIndex] = uiputfile('我的图像处理结果.bmp', '请指定图像文件的保存路劲') ;
    if FilterIndex ~= 0
        set(handles.my_static_text, 'String', fullfile(PathName, FileName));
    end
end
    
    
